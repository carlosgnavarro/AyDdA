#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar una actividad
struct Activity {
    int start, finish;
};

// Función de comparación para ordenar las actividades por tiempo de finalización
bool activityCompare(Activity a, Activity b) {
    return (a.finish < b.finish);
}

// Función para imprimir las actividades seleccionadas
void printMaxActivities(vector<Activity> activities) {
    // Ordenar las actividades por tiempo de finalización
    sort(activities.begin(), activities.end(), activityCompare);

    cout << "Las siguientes actividades son seleccionadas: " << endl;

    // La primera actividad siempre se selecciona
    int i = 0;
    cout << "Actividad " << i+1 << ": (" << activities[i].start << ", " << activities[i].finish << ")" << endl;

    // Considerar el resto de las actividades
    for (int j = 1; j < activities.size(); j++) {
        // Si esta actividad tiene un tiempo de inicio mayor o igual al tiempo de finalización
        // de la actividad previamente seleccionada, entonces seleccionarla
        if (activities[j].start >= activities[i].finish) {
            cout << "Actividad " << j+1 << ": (" << activities[j].start << ", " << activities[j].finish << ")" << endl;
            i = j;
        }
    }
}

// Función principal para probar el algoritmo
int main() {
    vector<Activity> activities = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};

    printMaxActivities(activities);

    return 0;
}