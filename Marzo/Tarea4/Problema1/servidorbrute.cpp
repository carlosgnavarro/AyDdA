#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // Required for numeric_limits

using namespace std;

int calculate_cost(int n, int u, int d, const vector<int>& morning_tasks, const vector<int>& evening_tasks, const vector<int>& assignment) {
    int total_cost = 0;
    for (int i = 0; i < n; ++i) {
        int total_load = morning_tasks[i] + evening_tasks[assignment[i]];
        int excess_load = max(0, total_load - u);
        total_cost += excess_load * d;
    }
    return total_cost;
}

int brute_force_min_cost(int n, int u, int d, const vector<int>& morning_tasks, const vector<int>& evening_tasks) {
    vector<int> assignment(n);
    for (int i = 0; i < n; ++i) {
        assignment[i] = i; // Initial assignment: morning task i to evening task i
    }

    int min_cost = numeric_limits<int>::max(); // Initialize with the largest possible integer

    do {
        int current_cost = calculate_cost(n, u, d, morning_tasks, evening_tasks, assignment);
        min_cost = min(min_cost, current_cost);
    } while (next_permutation(assignment.begin(), assignment.end()));

    return min_cost;
}

int main() {
    int n, u, d;
    while(cin >> n >> u >> d && (n != 0 && u != 0 && d != 0))
    {
        vector<int> morning_tasks(n), evening_tasks(n);
        for (int i = 0; i < n; ++i) {
            cin >> morning_tasks[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> evening_tasks[i];
        }
        int min_cost = brute_force_min_cost(n, u, d, morning_tasks, evening_tasks);
        cout << min_cost << endl;
    }

    return 0;
}