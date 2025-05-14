#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

vector<vector<int>> costoMin(vector<vector<int>> &matrizCostoEstacion, int n) {
    vector<vector<int>> matrizF = matrizCostoEstacion; 

    for (int i=0; i < n; i++) { 
        int tam = matrizCostoEstacion[i].size();
        for (int j=1; j < tam; j++) { 
            for (int k=1; k < j; k++) { 
                if (matrizF[i][j] > matrizF[i][k] + matrizF[i + k][j - k]) {
                    matrizF[i][j] = matrizF[i][k] + matrizF[i + k][j - k];
                }
            }
        }
    }

    return matrizF;
}


int main() {
    int k,n,costos;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>n;
        vector<vector<int>> matrizCostoEstacion(n), matrizFinal(n);
        for (int i=0; i < n; i++) {
            for (int j=0; j < n-i; j++) {
                cin >> costos;
                
                matrizCostoEstacion[i].push_back(costos);
            }
        }
        matrizFinal=costoMin(matrizCostoEstacion,n);
        for (int i = 0; i < matrizFinal.size(); ++i) {
            for (int j = 0; j < matrizFinal[i].size(); ++j) {
                cout << matrizFinal[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    

    return 0;
}

