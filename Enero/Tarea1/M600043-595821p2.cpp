#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int obtenerValorReducido(const string &nombre) {
    int suma = 0;
    for (int i=0;i<nombre.length();i++) {
        if (isalpha(nombre[i])) {
            suma += tolower(nombre[i]) - 'a' + 1;
        }
    }
    
    while (suma >= 10) {
        int nuevaSuma = 0;
        while (suma > 0) {
            nuevaSuma += suma % 10;
            suma /= 10;
        }
        suma = nuevaSuma;
    }
    
    return suma;
}

double calcularCompatibilidad(double valor1, double valor2) {
    if (valor1 > valor2){
        swap(valor1, valor2);
    }
    return (valor1 / valor2) * 100;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string nombre1, nombre2;
        getline(cin,nombre1);
        getline(cin,nombre2);
        
        double valor1 = obtenerValorReducido(nombre1);
        double valor2 = obtenerValorReducido(nombre2);
        
        double compatibilidad = calcularCompatibilidad(valor1, valor2);
        
        cout << fixed << setprecision(2)<< compatibilidad << endl;
    }
    
    return 0;
}
