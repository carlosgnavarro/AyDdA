#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Estructura para representar un nodo en el grafo
struct Node {
    int vertex;
    int distance;

    // Constructor
    Node(int v, int d) : vertex(v), distance(d) {}

    // Sobrecargar el operador < para la cola de prioridad
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

// Función para implementar el algoritmo de Dijkstra
void dijkstra(vector<vector<pair<int, int>>>& graph, int startVertex) {
    int numVertices = graph.size();
    vector<int> distances(numVertices, numeric_limits<int>::max());
    vector<bool> visited(numVertices, false);

    // La distancia al nodo de origen es 0
    distances[startVertex] = 0;

    // Cola de prioridad para obtener el nodo con la distancia mínima
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(Node(startVertex, 0));

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;

        // Si ya hemos visitado este nodo, continuar
        if (visited[u]) continue;

        visited[u] = true;

        // Recorrer todos los nodos adyacentes
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Si encontramos un camino más corto, actualizar la distancia
            if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push(Node(v, distances[v]));
            }
        }
    }

    // Imprimir las distancias más cortas desde el nodo de origen
    cout << "Distancias más cortas desde el nodo " << startVertex << ":" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Nodo " << i << ": " << distances[i] << endl;
    }
}

// Función principal para probar el algoritmo
int main() {
    int numVertices = 9;
    vector<vector<pair<int, int>>> graph(numVertices);

    // Agregar aristas al grafo
    graph[0].push_back({1, 4});
    graph[0].push_back({7, 8});
    graph[1].push_back({0, 4});
    graph[1].push_back({2, 8});
    graph[1].push_back({7, 11});
    graph[2].push_back({1, 8});
    graph[2].push_back({3, 7});
    graph[2].push_back({8, 2});
    graph[2].push_back({5, 4});
    graph[3].push_back({2, 7});
    graph[3].push_back({4, 9});
    graph[3].push_back({5, 14});
    graph[4].push_back({3, 9});
    graph[4].push_back({5, 10});
    graph[5].push_back({2, 4});
    graph[5].push_back({3, 14});
    graph[5].push_back({4, 10});
    graph[5].push_back({6, 2});
    graph[6].push_back({5, 2});
    graph[6].push_back({7, 1});
    graph[6].push_back({8, 6});
    graph[7].push_back({0, 8});
    graph[7].push_back({1, 11});
    graph[7].push_back({6, 1});
    graph[7].push_back({8, 7});
    graph[8].push_back({2, 2});
    graph[8].push_back({6, 6});
    graph[8].push_back({7, 7});

    dijkstra(graph, 0);

    return 0;
}