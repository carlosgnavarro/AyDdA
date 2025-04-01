#include <iostream>
#include <vector>

using namespace std;

int n, length;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;
bool found;

void dfs(int u) {
    visited[u] = true;
    path.push_back(u);

    if (path.size() - 1 == length) {
        found = true;
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    }

    visited[u] = false;
    path.pop_back();
}

int main() {
    while (cin >> n >> length) {
        adj.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);
        found = false;
        path.clear();

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int edge;
                cin >> edge;
                if (edge == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        dfs(1);

        if (!found) {
            cout << "no solution" << endl;
        }
    }

    return 0;
}