#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar una tarea
struct Job {
    char id;
    int deadline;
    int profit;
};

// Función de comparación para ordenar las tareas por beneficio
bool compareJobs(Job a, Job b) {
    return (a.profit > b.profit);
}

// Función para encontrar la secuencia de tareas
void jobScheduling(vector<Job> jobs, int numJobs) {
    // Ordenar las tareas por beneficio
    sort(jobs.begin(), jobs.end(), compareJobs);

    vector<int> slot(numJobs, 0);  // Inicializar todos los espacios como libres

    vector<char> result(numJobs);  // Almacenar el resultado final
    int totalProfit = 0;

    // Iterar a través de todas las tareas
    for (int i = 0; i < numJobs; i++) {
        // Encontrar un espacio libre para esta tarea (recorrer hacia atrás)
        for (int j = min(numJobs, jobs[i].deadline) - 1; j >= 0; j--) {
            // Si el espacio está libre, colocar la tarea en él y marcar el espacio como ocupado
            if (slot[j] == 0) {
                result[j] = jobs[i].id;
                slot[j] = 1;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Imprimir la secuencia de tareas programadas
    cout << "Secuencia de tareas programadas: ";
    for (int i = 0; i < numJobs; i++) {
        if (slot[i] == 1)
            cout << result[i] << " ";
    }
    cout << endl;
    cout << "Beneficio total = " << totalProfit << endl;
}

// Función principal para probar el algoritmo
int main() {
    vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    int numJobs = jobs.size();

    jobScheduling(jobs, numJobs);

    return 0;
}