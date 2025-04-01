#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num_prices;
    int case_num = 1;

    while (cin >> num_prices && num_prices != 0) {
        vector<string> prices(num_prices);
        for (int i = 0; i < num_prices; ++i) {
            cin >> prices[i];
        }

        string target;
        cin >> target;

        vector<string> result;
        bool possible = false;

        function<void(int, vector<string>)> solve = [&](int index, vector<string> current_result) {
            if (index == target.length()) {
                possible = true;
                result = current_result;
                return;
            }

            if (possible) return; // Optimization: If a solution is found, stop searching

            for (const string& price : prices) {
                if (target.substr(index, price.length()) == price) {
                    vector<string> next_result = current_result;
                    next_result.push_back(price);
                    solve(index + price.length(), next_result);
                }
            }
        };

        solve(0, {});

        cout << target << " = ";
        if (possible) {
            for (size_t i = 0; i < result.size(); ++i) {
                cout << result[i] << (i == result.size() - 1 ? "" : " ");
            }
        } else {
            cout << "Not possible to express";
        }
        cout << endl;
    }

    return 0;
}