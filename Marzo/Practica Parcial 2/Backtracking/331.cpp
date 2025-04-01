#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;
int min_swaps;
int num_solutions;

bool isSorted() {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void solve(int swaps) {
    if (isSorted()) {
        if (swaps < min_swaps) {
            min_swaps = swaps;
            num_solutions = 1;
        } else if (swaps == min_swaps) {
            num_solutions++;
        }
        return;
    }

    if (swaps > min_swaps) return;

    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            solve(swaps + 1);
            swap(arr[i], arr[i + 1]); // Backtrack
        }
    }
}

int main() {
    int case_num = 1;

    while (cin >> n && n != 0) {
        arr.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        min_swaps = n * (n - 1) / 2; // Maximum possible swaps
        num_solutions = 0;

        solve(0);

        cout << "There are " << num_solutions << " solution(s) in " << min_swaps << " swap(s)." << endl;
    }

    return 0;
}