#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para encontrar el mínimo número de monedas
void findMin(int amount, vector<int> coins) {
    // Ordenar las monedas en orden descendente
    sort(coins.begin(), coins.end(), greater<int>());

    vector<int> result;

    for (int i = 0; i < coins.size(); i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            result.push_back(coins[i]);
        }
    }

    cout << "Las monedas necesarias son: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

// Función principal para probar el algoritmo
int main() {
    int amount = 49;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    findMin(amount, coins);

    return 0;
}