#include <iostream>
#include <vector>

using namespace std;

int main() {
    int len, num_dominoes;

    while (cin >> len && len != 0) {
        cin >> num_dominoes;

        int left_end, right_end;
        cin >> left_end >> right_end;

        vector<pair<int, int>> dominoes(num_dominoes);
        for (int i = 0; i < num_dominoes; ++i) {
            cin >> dominoes[i].first >> dominoes[i].second;
        }

        bool possible = false;
        vector<bool> used(num_dominoes, false);
        vector<int> current_arrangement;

        function<void(int, int)> solve = [&](int current_len, int current_end) {
            if (current_len == len) {
                if (current_end == right_end) {
                    possible = true;
                }
                return;
            }

            for (int i = 0; i < num_dominoes; ++i) {
                if (!used[i]) {
                    if (dominoes[i].first == current_end) {
                        used[i] = true;
                        solve(current_len + 1, dominoes[i].second);
                        used[i] = false;
                    } else if (dominoes[i].second == current_end) {
                        used[i] = true;
                        solve(current_len + 1, dominoes[i].first);
                        used[i] = false;
                    }
                }
            }
        };

        solve(0, left_end);

        cout << (possible ? "YES" : "NO") << endl;
    }

    return 0;
}