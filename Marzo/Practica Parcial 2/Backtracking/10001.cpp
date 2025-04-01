#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int rule_num;
    string final_state;

    while (cin >> rule_num >> final_state) {
        string rule(8, '0');
        for (int i = 0; i < 8; ++i) {
            if (rule_num & (1 << i)) {
                rule[7 - i] = '1';
            }
        }

        bool possible = false;
        int n = final_state.length();

        for (int i = 0; i < (1 << n); ++i) {
            string initial_state(n, '0');
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    initial_state[j] = '1';
                }
            }

            string next_state(n, '0');
            for (int j = 0; j < n; ++j) {
                int left = (j - 1 + n) % n;
                int right = (j + 1) % n;

                string neighborhood;
                neighborhood += initial_state[left];
                neighborhood += initial_state[j];
                neighborhood += initial_state[right];

                int rule_index = 0;
                if (neighborhood[0] == '1') rule_index += 4;
                if (neighborhood[1] == '1') rule_index += 2;
                if (neighborhood[2] == '1') rule_index += 1;

                next_state[j] = rule[7 - rule_index];
            }

            if (next_state == final_state) {
                possible = true;
                break;
            }
        }

        cout << (possible ? "REACHABLE" : "GARDEN OF EDEN") << endl;
    }

    return 0;
}