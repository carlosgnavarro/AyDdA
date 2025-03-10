#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // servidores, capacidad, costo, tareas matutinas, tareas vespertinas, costo adicional respectivamente
    int computerserver,kapazitat,kosten,morgenaufgaben,abendaufgaben,zusatkosten;
    // vectores que contienen las tareas, matutinas y vespertinas
    vector<int> morgenaufgabenvector,abendaufgabenvector;
    while(cin >> computerserver >> kapazitat >> kosten && ((computerserver != 0) && (kapazitat != 0) && (kosten != 0)))
    {
        // relleno de vector de tareas matutinas
        for(int i = 0; i < computerserver; i++)
        {
            cin >> morgenaufgaben;
            morgenaufgabenvector.push_back(morgenaufgaben);
        }
        // relleno de vector de tareas vespertinas
        for(int i = 0; i < computerserver; i++)
        {
            cin >> abendaufgaben;
            abendaufgabenvector.push_back(abendaufgaben);
        }
        // ordenamiento de los vectores (ascendente) usando la expresion lambda
        sort(morgenaufgabenvector.begin(), morgenaufgabenvector.end(),[](int a, int b){ return a > b; });
        sort(abendaufgabenvector.begin(), abendaufgabenvector.end(),[](int a, int b){ return a > b; });
        zusatkosten = 0;
        for(int i = 0; i < computerserver; i++)
        {
            // greedy (agarra el valor mas prometedor de ambos vectores y saca el costo adicional resultante)
            zusatkosten +=  (morgenaufgabenvector[i] + abendaufgabenvector[computerserver - i - 1] - kapazitat) * kosten;
        }
        if(zusatkosten > 0)
        {
            cout << zusatkosten << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        morgenaufgabenvector.clear();
        abendaufgabenvector.clear();
    }
    return 0;
}