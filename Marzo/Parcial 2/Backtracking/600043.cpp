// Carlos Emiliano Navarro Gamiño, Matricula: 600043
// Analisis y Diseño de Algoritmos, Parcial 2, parte 2: backtracking

#include <iostream>
#include <vector>

using namespace std;

long coeficienteBinomial(int n, int k) 
{
    if (k == n)
    {
        return 1;
    }
    if (k > n / 2)
    {
        k = n - k;
    }
    int res = 1;
    for (int i = 0; i < k; ++i) 
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// No me cabian con int para casos mayores a 11
long campanaOrdenada(int n) 
{
    vector<long> a(n + 1);
    a[0] = 1;
    for (int i = 1; i <= n; ++i) 
    {
        a[i] = 0;
        for (int j = 1; j <= i; ++j) 
        {
            a[i] += coeficienteBinomial(i, j) * a[i - j];
        }
    }
    return a[n];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << campanaOrdenada(n) << endl;
    }
    return 0;
}