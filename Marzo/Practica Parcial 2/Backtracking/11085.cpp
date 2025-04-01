#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int initial_positions[8];
int best_moves;

bool isSafe(int row, int col, vector<int>& queens) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(int row, vector<int>& queens, int moves) {
    if (row == 8) {
        best_moves = min(best_moves, moves);
        return;
    }

    for (int col = 0; col < 8; ++col) {
        if (isSafe(row, col, queens)) {
            queens[row] = col;
            solve(row + 1, queens, moves + (col != initial_positions[row]));
        }
    }
}

int main() {
    int case_num = 1;

    while (cin >> initial_positions[0]) {
        for (int i = 1; i < 8; ++i) {
            cin >> initial_positions[i];
            initial_positions[i]--; // 0-based indexing
        }
        initial_positions[0]--; // 0-based indexing

        best_moves = INT_MAX;
        vector<int> queens(8, -1);
        solve(0, queens, 0);

        cout << "Case " << case_num++ << ": " << best_moves << endl;
    }

    return 0;
}