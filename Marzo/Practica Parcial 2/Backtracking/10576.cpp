#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s, d;
int max_profit;

void solve(int month, vector<int>& profits, int current_profit) {
    if (month == 12) {
        max_profit = max(max_profit, current_profit);
        return;
    }

    // Try +s
    profits[month] = s;
    bool valid = true;
    for (int i = month - 4; i <= month; ++i) {
        if (i < 0) continue;
        int sum = 0;
        for (int j = i; j < i + 5; ++j) {
            sum += profits[j];
        }
        if (sum >= 0) {
            valid = false;
            break;
        }
    }
    if (valid) {
        solve(month + 1, profits, current_profit + s);
    }

    // Try -d
    profits[month] = -d;
    valid = true;
    for (int i = month - 4; i <= month; ++i) {
        if (i < 0) continue;
        int sum = 0;
        for (int j = i; j < i + 5; ++j) {
            sum += profits[j];
        }
        if (sum >= 0) {
            valid = false;
            break;
        }
    }
    if (valid) {
        solve(month + 1, profits, current_profit - d);
    }
}

int main() {
    while (cin >> s >> d) {
        max_profit = -1;
        vector<int> profits(12, 0);
        solve(0, profits, 0);

        if (max_profit == -1) {
            cout << "Deficit" << endl;
        } else {
            cout << max_profit << endl;
        }
    }

    return 0;
}