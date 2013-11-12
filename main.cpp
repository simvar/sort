#include <iostream>
#include <stdlib.h>
template <class T> void exch(T &, T &);
template <class T> void compexch(T &, T &);
template <class T> void selection(T *, int, int);
template <class T> void insertion(T *, int, int);
template <class T> void bubble(T *, int, int);
using namespace std;
int main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]), KaDaryt = atoi(argv[2]);
    int *a = new int[N];
    if (KaDaryt) // Atsitiktinai sugeneruoja N skai�i� intervale: 1,...,1000.
      for (i = 0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
    else // Savo nuo�i�ra �vedame skai�ius. Nor�dami baigti �vedim�, �vedame bet kok� simbol� - ne skai�i�.
      { N = 0; while (cin >> a[N]) N++; }
    cout << "�vestas skai�i� masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    selection(a, 0, N-1);
    cout << "Sur��iuotas skai�i� masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
}
// Sukei�ia elementus vietomis
template <class T>
  void exch(T &A, T &B)
    { T t = A ; A = B; B = t; }
// Sukei�ia elementus vietomis tik jei patenkinta s�lyga
template <class T>
  void compexch(T &A, T &B)
    { if (B < A) exch(A, B); }
// I�rinkimo algoritmo realizacija
template <class T>
void selection(T a[], int l, int r)
  { for (int i = l; i < r; i++)
      { int min = i;
        for (int j = i+1; j <= r; j++)
            if (a[j] < a[min]) min = j;
        exch(a[i], a[min]);
      }
  }
// �terpimo algoritmo realizacija
template <class T>
void insertion(T a[], int l, int r)
  { int i;
    for (i = r; i > l; i--) compexch(a[i-1], a[i]);
    for (i = l+2; i <= r; i++)
      { int j = i; T v = a[i];
        while (v < a[j-1])
          { a[j] = a[j-1]; j--; }
        a[j] = v;
      }
  }
// Burbulo algoritmas
template <class T>
void bubble(T a[], int l, int r)
  { for (int i = l; i < r; i++)
      for (int j = r; j > i; j--)
        compexch(a[j-1], a[j]);
  }

