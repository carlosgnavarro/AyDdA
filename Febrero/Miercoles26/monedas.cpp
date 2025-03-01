#include <iostream>
#include <vector>

using namespace std;

int greed(vector<int> &monedas, int objetivo)
{
    int i;
    for(i = monedas.size()-1; monedas[i] > objetivo; i--);
    return i;
}

int main()
{
    vector<int> monedas = {1,2,5,10,20};
    vector<int> solucion = {0,0,0,0,0};
    int objetivo;
    cin >> objetivo;
    while(objetivo > 0)
    {
        solucion[greed(monedas,objetivo)]++;
        objetivo-=monedas[greed(monedas,objetivo)];
    }
    for(int i = monedas.size(); i >= 0; i--)
    {
        if(solucion[i] > 0)
        {
            cout << "Dar " << solucion[i] << " de " << monedas[i] << endl;
        }
    }
    return 0;
}