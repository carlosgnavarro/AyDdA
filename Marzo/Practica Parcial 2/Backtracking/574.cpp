#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int target, n;
vector<int> numbers;
set<vector<int>> solutions;
vector<int> current_solution;

void solve(int index, int current_sum) {
    if (current_sum == target) {
        vector<int> sorted_solution = current_solution;
        sort(sorted_solution.rbegin(), sorted_solution.rend()); // Sort in descending order
        solutions.insert(sorted_solution);
        return;
    }

    if (index == n || current_sum > target) {
        return;
    }

    // Option 1: Include the current number
    current_solution.push_back(numbers[index]);
    solve(index + 1, current_sum + numbers[index]);
    current_solution.pop_back(); // Backtrack

    // Option 2: Exclude the current number
    solve(index + 1, current_sum);
}

int main() {
    while (cin >> target >> n && (target || n)) {
        numbers.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }

        solutions.clear();
        current_solution.clear();

        solve(0, 0);

        cout << "Sums of " << target << ":" << endl;
        if (solutions.empty()) {
            cout << "NONE" << endl;
        } else {
            vector<vector<int>> sorted_solutions(solutions.rbegin(), solutions.rend()); // Sort in reverse order
            for (const auto& solution : sorted_solutions) {
                for (size_t i = 0; i < solution.size(); ++i) {
                    cout << solution[i] << (i == solution.size() - 1 ? "" : "+");
                }
                cout << endl;
            }
        }
    }

    return 0;
}