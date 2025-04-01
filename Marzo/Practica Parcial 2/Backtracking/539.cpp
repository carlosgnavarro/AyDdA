#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_path;

void dfs(int node, vector<vector<int>>& adj, vector<vector<bool>>& visited, int current_length) {
    longest_path = max(longest_path, current_length);

    for (int neighbor : adj[node]) {
        if (!visited[node][neighbor]) {
            visited[node][neighbor] = visited[neighbor][node] = true;
            dfs(neighbor, adj, visited, current_length + 1);
            visited[node][neighbor] = visited[neighbor][node] = false; // Backtrack
        }
    }
}

int main() {
    int n, m;

    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<vector<int>> adj(n);
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        longest_path = 0;
        for (int i = 0; i < n; ++i) {
            dfs(i, adj, visited, 0);
        }

        cout << longest_path << endl;
    }

    return 0;
}