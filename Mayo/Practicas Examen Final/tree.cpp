#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Edge {
    int to, weight;
};

int find(vector<int>& parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
    x = find(parent, x);
    y = find(parent, y);
    if (x != y) {
        if (rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
}

int main() {
    int numVertices, numEdges;
    while (cin >> numVertices >> numEdges && (numVertices != 0 || numEdges != 0)) {
        map<string, int> stationIndex;
        vector<string> stationName(numVertices);
        for (int i = 0; i < numVertices; ++i) {
            cin >> stationName[i];
            stationIndex[stationName[i]] = i;
        }

        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < numEdges; ++i) {
            string station1, station2;
            int weight;
            cin >> station1 >> station2 >> weight;
            int u = stationIndex[station1];
            int v = stationIndex[station2];
            edges.emplace_back(weight, u, v);
        }

        string startStation;
        cin >> startStation;

        sort(edges.begin(), edges.end());

        vector<int> parent(numVertices);
        vector<int> rank(numVertices, 0);
        for (int i = 0; i < numVertices; ++i)
            parent[i] = i;

        int mstWeight = 0;
        int edgeCount = 0;
        for (const auto& edge : edges) {
            int weight, u, v;
            tie(weight, u, v) = edge;
            if (find(parent, u) != find(parent, v)) {
                unite(parent, rank, u, v);
                mstWeight += weight;
                edgeCount++;
            }
            if (edgeCount == numVertices - 1)
                break;
        }

        if (edgeCount == numVertices - 1)
            cout << mstWeight << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}