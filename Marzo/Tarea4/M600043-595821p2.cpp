#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int loopsmaximos(int n, vector<int>& loops) {
    sort(loops.rbegin(), loops.rend());
    int numMax = 0;

    for (int i = 0; i < n; i++) {
        int tmp_total = loops[i], loopsU=1; 
        vector<bool> u(n, false);
        u[i] = true;

        for (int j = 0; j < n && tmp_total > 0; j++) {
            if (!u[j] && tmp_total >= loops[j]) {
                loopsU++;
                u[j] = true;
                tmp_total -= loops[j];
            }
        }

        numMax = max(numMax, loopsU);
    }

    return numMax;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> loops(n);
        for (int i = 0; i < n; i++) {
            cin >> loops[i];
        }
        cout << loopsmaximos(n, loops) << endl;
    }
    return 0;
}