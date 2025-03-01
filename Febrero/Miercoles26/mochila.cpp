#include <iostream>
#include <vector>

using namespace std;

int greed(vector<pair<int,int>> &objetos, vector<bool> used)
{
    for(int i = objetos.size(); i > 0; i--)
    {
        if(used[i] == false)
        {
            return i;
        }

    }
    return -1;
}

int main()
{
    vector<pair<int,int>> objetos;
    vector<int> peso = {10,20,30,40,50};
    vector<int> valor = {20,30,66,40,60};
    for(int i = 0; i < peso.size(); i++)
    {
        objetos.push_back(make_pair(valor[i],peso[i]));
    }
    vector<bool> used(5,false);
    vector<int> solucion;
    int capacidad = 100;
    sort(objetos.begin(),objetos.end());
    while(capacidad > 0 and find(used.begin(),used.end(),false) != used.end())
    {
        int ix = greed(objetos,used);
        if(objetos[ix].second <= capacidad)
        {
            solucion.push_back(ix);
            capacidad-=objetos[ix].second;
        }
        used[ix] = true;
    }
    int gain = 0;
    for(int i = 0; i < solucion.size(); i++)
    {
        cout << solucion[i] << endl;
        gain += objetos[solucion[i]].first;
    }
    cout << gain << endl;
    return 0;
}