#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    vector <int> costoPorExtra;
    int caso =0;
        for (int i =0; i != -2; i++){
            int cantServidores= 0, cantProcesadores =0;
            int suma =0, cantTOTALprcs =0, extras=0, cantTotExtras=0, costo =0;
            cin >> cantServidores >> cantProcesadores >> costo;
            if(cantServidores == 0 && cantProcesadores == 0 && costo == 0)
                break;
            else {
                vector<int> procesMat;
                vector<int> procesVes;
                for(int j =0; j < cantServidores; j++){
                    int PrcsQtyMat =0;
                    cin >> PrcsQtyMat;
                    procesMat.push_back(PrcsQtyMat);
                    int PrcsQtyVes =0;
                    cin >> PrcsQtyVes;
                    procesVes.push_back(PrcsQtyVes);
                    suma += PrcsQtyVes + PrcsQtyMat;

                }
                cantTOTALprcs = cantProcesadores*cantServidores;
                extras = suma - cantTOTALprcs;
                if(extras > 0){
                    cantTotExtras = extras * costo;
                }
                costoPorExtra.push_back(cantTotExtras);
            }
            caso++;
        }
        for(int c =0; c < caso; c++){
            cout << costoPorExtra[c] << endl;
        }
    return 0;
}