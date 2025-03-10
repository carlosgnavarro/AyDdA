#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // servidores, capacidad, costo, tareas matutinas, tareas vespertinas, costo adicional respectivamente
    int computerserver,kapazitat,kosten;
    while(cin >> computerserver >> kapazitat >> kosten && (computerserver != 0 && kapazitat != 0 && kosten != 0))
    {
        vector<long long> morgenaufgaben(computerserver),abendaufgaben(computerserver);
        // relleno de vector de tareas matutinas
        for(int i = 0; i < computerserver; i++)
        {
            cin >> morgenaufgaben[i];
        }
        // relleno de vector de tareas vespertinas
        for(int i = 0; i < computerserver; i++)
        {
            cin >> abendaufgaben[i];
        }
        // ordenamiento de los vectores (descendente)
        sort(morgenaufgaben.begin(), morgenaufgaben.end());
        sort(abendaufgaben.rbegin(), abendaufgaben.rend());
        long long zusatkosten = 0;
        for(int i = 0; i < computerserver; i++)
        {
            long long zum = morgenaufgaben[i] + abendaufgaben[i];
            if(zum > kapazitat)
            {
                zusatkosten += (zum - kapazitat) * kosten;
            }
        }
        if(zusatkosten > 0)
        {
            cout << zusatkosten << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}