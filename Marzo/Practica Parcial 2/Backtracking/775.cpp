#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;

bool solve(int u) {
    visited[u] = true;
    path.push_back(u);

    if (path.size() == n) {
        // Check if there is an edge between the last node and the first node
        for (int v : adj[u]) {
            if (v == path[0]) {
                return true;
            }
        }
        visited[u] = false;
        path.pop_back();
        return false;
    }

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (solve(v)) {
                return true;
            }
        }
    }

    visited[u] = false;
    path.pop_back();
    return false;
}

int main() {
    int u, v;

    while (cin >> n) {
        adj.assign(n + 1, vector<int>());
        while (cin >> u >> v && (u != 0 || v != 0)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visited.assign(n + 1, false);
        path.clear();

        bool has_hamiltonian_cycle = false;
        for (int i = 1; i <= n; ++i) {
            if (solve(i)) {
                has_hamiltonian_cycle = true;
                break;
            }
            visited.assign(n + 1, false);
            path.clear();
        }

        cout << (has_hamiltonian_cycle ? "1" : "0") << endl;
    }

    return 0;
}