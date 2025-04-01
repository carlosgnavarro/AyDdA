#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int capacity, num_stations, num_requests;
vector<tuple<int, int, int>> requests;
int max_profit;

void solve(int request_index, vector<int>& train_load, int current_profit) {
    if (request_index == num_requests) {
        max_profit = max(max_profit, current_profit);
        return;
    }

    int start, end, passengers;
    tie(start, end, passengers) = requests[request_index];

    // Option 1: Don't accept the request
    solve(request_index + 1, train_load, current_profit);

    // Option 2: Accept the request (if possible)
    bool possible = true;
    for (int i = start; i < end; ++i) {
        if (train_load[i] + passengers > capacity) {
            possible = false;
            break;
        }
    }

    if (possible) {
        for (int i = start; i < end; ++i) {
            train_load[i] += passengers;
        }
        solve(request_index + 1, train_load, current_profit + passengers * (end - start));
        for (int i = start; i < end; ++i) {
            train_load[i] -= passengers; // Backtrack
        }
    }
}

int main() {
    while (cin >> capacity >> num_stations >> num_requests && (capacity || num_stations || num_requests)) {
        requests.resize(num_requests);
        for (int i = 0; i < num_requests; ++i) {
            cin >> get<0>(requests[i]) >> get<1>(requests[i]) >> get<2>(requests[i]);
            get<0>(requests[i])--; // 0-based indexing
            get<1>(requests[i])--; // 0-based indexing
        }

        max_profit = 0;
        vector<int> train_load(num_stations, 0);
        solve(0, train_load, 0);

        cout << max_profit << endl;
    }

    return 0;
}