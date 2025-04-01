#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[8][8];
int max_sum;

bool isSafe(int row, int col, vector<int>& queens) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(int row, vector<int>& queens, int current_sum) {
    if (row == 8) {
        max_sum = max(max_sum, current_sum);
        return;
    }

    for (int col = 0; col < 8; ++col) {
        if (isSafe(row, col, queens)) {
            queens[row] = col;
            solve(row + 1, queens, current_sum + board[row][col]);
        }
    }
}

int main() {
    int k;
    cin >> k;

    while (k--) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cin >> board[i][j];
            }
        }

        max_sum = 0;
        vector<int> queens(8, -1);
        solve(0, queens, 0);

        printf("%5d\n", max_sum);
    }

    return 0;
}