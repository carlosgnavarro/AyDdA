#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
int count_convex;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col, const vector<int>& queens) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Function to check if a set of points forms a convex polygon
bool isConvex(const vector<pair<int, int>>& points) {
    int n = points.size();
    if (n < 3) return true; // A line or point is considered convex

    bool positive = false;
    bool negative = false;

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;

        int cross_product = (points[j].first - points[i].first) * (points[k].second - points[i].second) -
                            (points[j].second - points[i].second) * (points[k].first - points[i].first);

        if (cross_product > 0) positive = true;
        if (cross_product < 0) negative = true;

        if (positive && negative) return false; // Not convex
    }

    return true;
}

// Recursive function to generate N-Queens configurations
void solveNQueens(int row, vector<int>& queens) {
    if (row == n) {
        // Found a valid N-Queens configuration
        vector<pair<int, int>> points;
        for (int i = 0; i < n; ++i) {
            points.push_back({i, queens[i]}); // Store as (row, col)
        }

        if (isConvex(points)) {
            count_convex++;
        }
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, queens)) {
            queens[row] = col;
            solveNQueens(row + 1, queens);
        }
    }
}

int main() {
    while (cin >> n) {
        count_convex = 0;
        vector<int> queens(n);
        solveNQueens(0, queens);

        cout << count_convex << endl;
    }

    return 0;
}