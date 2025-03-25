#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar una arista
struct Edge {
    int src, dest, weight;
};

// Estructura para representar un subconjunto para la búsqueda de conjuntos disjuntos
struct Subset {
    int parent, rank;
};

// Función para encontrar el conjunto de un elemento 'i' (con compresión de ruta)
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Función para realizar la unión por rango
void unite(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Función principal para ejecutar el algoritmo de Kruskal
void kruskalMST(vector<Edge>& edges, int numVertices) {
    vector<Edge> result;  // Almacena el árbol de expansión mínimo resultante
    int e = 0;  // Índice para iterar a través de las aristas ordenadas
    int i = 0;  // Índice para el resultado[]

    // Ordenar todas las aristas en orden no decreciente de su peso
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    // Asignar memoria para crear V subconjuntos
    vector<Subset> subsets(numVertices);
    for (int v = 0; v < numVertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // El número de aristas a incluir será V-1
    while (result.size() < numVertices - 1 && i < edges.size()) {
        // Tomar la arista más pequeña
        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // Si la inclusión de esta arista causa un ciclo, descartarla
        if (x != y) {
            result.push_back(next_edge);
            unite(subsets, x, y);
        }
        // De lo contrario, descartar la arista
    }

    // Imprimir el contenido del resultado[] para mostrar las aristas construidas
    cout << "Aristas en el árbol de expansión mínimo construido:" << endl;
    int minimumCost = 0;
    for (auto& edge : result) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        minimumCost += edge.weight;
    }
    cout << "Costo mínimo = " << minimumCost << endl;
}

// Función principal para probar el algoritmo
int main() {
    int numVertices = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, numVertices);

    return 0;
}