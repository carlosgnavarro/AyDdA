#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, u, d;

    while (cin >> n >> u >> d && (n != 0 && u != 0 && d != 0)) {
        vector<int> morning_tasks(n);
        vector<int> evening_tasks(n);

        for (int i = 0; i < n; ++i) {
            cin >> morning_tasks[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> evening_tasks[i];
        }

        long long total_cost = 0;
        
        // Create pairs of tasks and sort them by the sum of their processing units
        vector<pair<int, int>> task_pairs;
        for (int i = 0; i < n; ++i) {
            task_pairs.push_back({morning_tasks[i], evening_tasks[i]});
        }

        vector<bool> assigned(n, false); // Keep track of assigned tasks

        for (int i = 0; i < n; ++i) {
            int best_morning_index = -1;
            int best_evening_index = -1;
            long long min_cost = -1;

            for (int j = 0; j < n; ++j) {
                if (!assigned[j]) {
                    for (int k = 0; k < n; ++k) {
                        if (!assigned[k]) {
                            long long current_cost = 0;
                            int total_load = morning_tasks[j] + evening_tasks[k];
                            if (total_load > u) {
                                current_cost = (long long)(total_load - u) * d;
                            }

                            cout << "Par: " << morning_tasks[j] << ", " << evening_tasks[k] << endl;
                            cout << "Carga total: " << total_load << endl;
                            cout << "Costo actual: " << current_cost << endl;

                            if (best_morning_index == -1 || current_cost < min_cost) {
                                best_morning_index = j;
                                best_evening_index = k;
                                min_cost = current_cost;
                            }
                        }
                    }
                }
            }

            assigned[best_morning_index] = true;
            assigned[best_evening_index] = true;
            total_cost += min_cost;
        }

        cout << total_cost << endl;
    }

    return 0;
}