#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Función para resolver el problema de carga de barcos con fuerza bruta y priorización
void cargarBarcos(int capacidadMaxima, const vector<int>& pesos) {
    int n = pesos.size();
    int maxCarga = 0;
    vector<int> mejorCombinacion;

    // Generar todas las posibles combinaciones de contenedores
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> combinacionActual;
        int cargaActual = 0;

        // Construir la combinación actual y calcular su carga
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) { // Si el j-ésimo bit está activado, incluir el contenedor
                if (cargaActual + pesos[j] <= capacidadMaxima) {
                    combinacionActual.push_back(pesos[j]);
                    cargaActual += pesos[j];
                } else {
                    cargaActual = capacidadMaxima + 1; // Excede la capacidad, invalidar la combinación
                    break;
                }
            }
        }

        // Verificar si la combinación actual es válida
        if (cargaActual <= capacidadMaxima) {
            // Si la carga actual es mayor que la máxima anterior, actualizar
            if (cargaActual > maxCarga) {
                maxCarga = cargaActual;
                mejorCombinacion = combinacionActual;
            } else if (cargaActual == maxCarga && !mejorCombinacion.empty()) {
                // Si la carga actual es igual a la máxima anterior,
                // verificar si la combinación actual tiene mayor prioridad
                // (aparecen primero en la lista)
                bool prioridadActualEsMejor = false;
                size_t k = 0;
                while (k < combinacionActual.size() && k < mejorCombinacion.size()) {
                    auto itActual = find(pesos.begin(), pesos.end(), combinacionActual[k]);
                    auto itMejor = find(pesos.begin(), pesos.end(), mejorCombinacion[k]);
                    if (distance(pesos.begin(), itActual) < distance(pesos.begin(), itMejor)) {
                        prioridadActualEsMejor = true;
                        break;
                    } else if (distance(pesos.begin(), itActual) > distance(pesos.begin(), itMejor)) {
                        break;
                    }
                    k++;
                }
                if (prioridadActualEsMejor) {
                    mejorCombinacion = combinacionActual;
                }
            } else if (cargaActual == maxCarga && mejorCombinacion.empty()) {
                mejorCombinacion = combinacionActual;
            }
        }
    }

    // Imprimir el resultado
    cout << maxCarga << " =";
    for (size_t i = 0; i < mejorCombinacion.size(); ++i) {
        cout << " " << mejorCombinacion[i];
    }
    cout << endl;
}

int main() {
    int capacidadMaxima, numContenedores;

    // Leer los casos de prueba hasta que se ingrese 0 0
    while (cin >> capacidadMaxima >> numContenedores && (capacidadMaxima != 0 || numContenedores != 0)) {
        vector<int> pesos(numContenedores);
        for (int i = 0; i < numContenedores; ++i) {
            cin >> pesos[i];
        }

        cargarBarcos(capacidadMaxima, pesos);
    }

    return 0;
}