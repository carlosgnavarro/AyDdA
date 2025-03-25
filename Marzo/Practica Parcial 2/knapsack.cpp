#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar un elemento
struct Item {
    int value, weight;
};

// Función de comparación para ordenar los elementos por relación valor/peso
bool compareItems(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

// Función para resolver el problema de la mochila fraccionaria
double fractionalKnapsack(int capacity, vector<Item> items) {
    // Ordenar los elementos por relación valor/peso
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;

    for (auto& item : items) {
        if (item.weight <= capacity) {
            // Si el elemento cabe completamente en la mochila, agregarlo
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            // Si no, tomar una fracción del elemento
            totalValue += (double)item.value / item.weight * capacity;
            break;
        }
    }

    return totalValue;
}

// Función principal para probar el algoritmo
int main() {
    int capacity = 50;
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Valor máximo que se puede obtener = " << maxValue << endl;

    return 0;
}