#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, caseNum = 0;

    while (cin >> n >> m && (n != 0 || m != 0)) {
        int bachelors[n];
        int spinsters[m];

        int minBachelorAge = 100; // Initialize with a large value
        for (int i = 0; i < n; ++i) {
            cin >> bachelors[i];
            minBachelorAge = min(minBachelorAge, bachelors[i]);
        }

        for (int i = 0; i < m; ++i) {
            cin >> spinsters[i];
        }

        cout << "Case " << ++caseNum << ": ";
        if (n <= m) {
            cout << 0 << endl;
        } else {
            cout << n - m << " " << minBachelorAge << endl;
        }
    }

    return 0;
}