#include <iostream>
#include <vector>

using namespace std;

// Function to calculate binomial coefficient (n choose k)
long long binomialCoeff(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k; // Optimization: nCk = nC(n-k)

    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// Function to calculate ordered Bell number using the recursive formula
long long orderedBell(int n) {
    if (n == 0) return 1;

    vector<long long> a(n + 1);
    a[0] = 1;

    for (int i = 1; i <= n; ++i) {
        a[i] = 0;
        for (int j = 1; j <= i; ++j) {
            a[i] += binomialCoeff(i, j) * a[i - j];
        }
    }
    return a[n];
}

int main() {
    int cant;
    cin >> cant;
    while (cant--) {
        int n;
        cin >> n;
        cout << orderedBell(n) << endl;
    }
    return 0;
}