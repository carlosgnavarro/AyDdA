#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        int m, n;
        cin >> m >> n;

        vector<string> grid(m);
        for (int i = 0; i < m; ++i) {
            cin >> grid[i];
        }

        vector<string> path;
        int row = m - 1;
        int col;
        for (int j = 0; j < n; ++j) {
            if (grid[row][j] == 'M') {
                col = j;
                break;
            }
        }

        string target = "IEHOVA";
        int target_index = 0;

        while (row > 0) {
            if (col > 0 && grid[row - 1][col - 1] == target[target_index]) {
                path.push_back("left");
                row--;
                col--;
            } else if (col < n - 1 && grid[row - 1][col + 1] == target[target_index]) {
                path.push_back("right");
                row--;
                col++;
            } else {
                path.push_back("forth");
                row--;
            }
            target_index++;
        }

        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}