#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        int n, k;
        cin >> n >> k;
        string dna;
        cin >> dna;

        int mutations = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (dna[i] != dna[n - i - 1]) {
                mutations++;
            }
        }

        if (mutations <= k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}