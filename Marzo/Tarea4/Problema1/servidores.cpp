#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

int main() {
    int n;
    int u, d;

    cin >> n >> u >> d;

    vector<int> morning_tasks(n);
    vector<int> evening_tasks(n);

    for (int i = 0; i < n; ++i) {
        cin >> morning_tasks[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> evening_tasks[i];
    }

    // 1. Calculate Individual Task "Pressure" and 2. Sort by Combined Pressure
    // Store pairs as tuples: (morning_index, evening_index, combined_pressure)
    vector<tuple<int, int, int>> task_pairs;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double combined_pressure = (morning_tasks[i] / u) + (evening_tasks[j] / u);
            task_pairs.emplace_back(i, j, combined_pressure); // Use emplace_back for efficiency
        }
    }

    sort(task_pairs.begin(), task_pairs.end(), [](const tuple<int, int, double>& a, const tuple<int, int, double>& b) {
        return get<2>(a) > get<2>(b); // Compare based on combined_pressure (element at index 2)
    });

    // 3. Iterative Assignment
    vector<bool> morning_assigned(n, false);
    vector<bool> evening_assigned(n, false);
    vector<pair<int, int>> assignments; // Store (morning_index, evening_index) pairs

    for (const auto& tp : task_pairs) {
        int m_index = get<0>(tp); // Get morning_index from tuple
        int e_index = get<1>(tp); // Get evening index from tuple

        if (!morning_assigned[m_index] && !evening_assigned[e_index]) {
            assignments.push_back({m_index, e_index});
            morning_assigned[m_index] = true;
            evening_assigned[e_index] = true;
        }
    }

    // 4. Handle Remaining Tasks
    vector<int> unassigned_morning;
    vector<int> unassigned_evening;

    for (int i = 0; i < n; ++i) {
        if (!morning_assigned[i]) {
            unassigned_morning.push_back(i);
        }
        if (!evening_assigned[i]) {
            unassigned_evening.push_back(i);
        }
    }

    // Pair remaining tasks greedily (least demanding)
    sort(unassigned_morning.begin(), unassigned_morning.end(), [&](int a, int b) {
        return morning_tasks[a] < morning_tasks[b];
    });
    sort(unassigned_evening.begin(), unassigned_evening.end(), [&](int a, int b) {
        return evening_tasks[a] < evening_tasks[b];
    });

    int num_unassigned = min(unassigned_morning.size(), unassigned_evening.size());
    for (int i = 0; i < num_unassigned; ++i) {
        assignments.push_back({unassigned_morning[i], unassigned_evening[i]});
    }

    // 5. Calculate Total Cost
    double total_cost = 0;
    for (const auto& assignment : assignments) {
        int m_index = assignment.first;
        int e_index = assignment.second;
        double total_load = morning_tasks[m_index] + evening_tasks[e_index];
        double excess = max(0.0, total_load - u);
        total_cost += excess * d;
    }

    cout << round(total_cost) << endl;

    return 0;
}