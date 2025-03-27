// Carlos Emiliano Navarro Gamiño, Matricula: 600043
// Analisis y Diseño de Algoritmos
// Parcial #2 pt.1 "Greedy"

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int H, M;
    int caso = 1;
    while(cin >> H >> M and (H != 0 and M != 0))
    {
        int onvres[H];
        int mujeres[M];
        int masjoven = 100;
        for(int i = 0; i < H; i++)
        {
            cin >> onvres[i];
            masjoven = min(masjoven,onvres[i]);
        }
        for(int i = 0; i < M; i++)
        {
            cin >> mujeres[i];
        }
        cout << "Caso " << caso++ << ": ";
        if(H <= M)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << H-M << " " << masjoven << endl;
        }
    }
    return 0;
}

// Doy mi palabra de que he realizado esta evaluacion con integridad académica