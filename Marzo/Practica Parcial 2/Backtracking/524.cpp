#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> ring;
vector<bool> used;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void solve(int k) {
    if (k == n) {
        if (isPrime(ring[n - 1] + ring[0])) {
            for (int i = 0; i < n; ++i) {
                cout << ring[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
        }
        return;
    }

    for (int i = 2; i <= n; ++i) {
        if (!used[i] && isPrime(ring[k - 1] + i)) {
            ring[k] = i;
            used[i] = true;
            solve(k + 1);
            used[i] = false; // Backtrack
        }
    }
}

int main() {
    int case_num = 1;

    while (cin >> n) {
        if (case_num > 1) cout << endl;
        cout << "Case " << case_num++ << ":" << endl;

        ring.resize(n);
        used.assign(n + 1, false);

        ring[0] = 1;
        used[1] = true;

        solve(1);
    }

    return 0;
}