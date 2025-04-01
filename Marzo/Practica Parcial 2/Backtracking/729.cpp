#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        int n, h;
        cin >> n >> h;

        string s(n, '0');
        for (int i = 0; i < h; ++i) {
            s[n - 1 - i] = '1';
        }

        sort(s.begin(), s.end());

        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end()));

        if (num_test_cases > 0) {
            cout << endl;
        }
    }

    return 0;
}