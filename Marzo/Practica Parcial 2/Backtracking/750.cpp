#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int a, b;
int solutions[92][8];
int num_solutions = 0;

bool isSafe(int row, int col, vector<int>& queens) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(int row, vector<int>& queens) {
    if (row == 8) {
        // Check if the given queen is in the correct position
        if (queens[a - 1] == b - 1) {
            for (int i = 0; i < 8; ++i) {
                solutions[num_solutions][i] = queens[i] + 1;
            }
            num_solutions++;
        }
        return;
    }

    for (int col = 0; col < 8; ++col) {
        if (isSafe(row, col, queens)) {
            queens[row] = col;
            solve(row + 1, queens);
        }
    }
}

int main() {
    int k;
    cin >> k;

    vector<int> queens(8, -1);
    solve(0, queens);

    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl;
    cout << endl;

    while (k--) {
        cin >> a >> b;

        int count = 1;
        for (int i = 0; i < num_solutions; ++i) {
            bool matches_given = true;
            if (matches_given) {
                cout << setw(2) << right << count++ << "     ";
                for (int j = 0; j < 8; ++j) {
                    cout << setw(2) << right << solutions[i][j] << " ";
                }
                cout << endl;
            }
        }
        if (k > 0)
            cout << endl;
    }

    return 0;
}