#include <iostream>
#include <vector>

using namespace std;


void conseguirBoletos(int dconseguido, vector<int>& boletos,int nboletos)
{
    int a,b;
    int maxdiff = 999999999;
    for(int i = 0; i <= nboletos; i++)
    {
        for(int x = i+1; x <= nboletos; x++)
        {
            if(boletos[i]+boletos[x] == dconseguido)
            {
                if(abs(boletos[i]-boletos[x]) < maxdiff)
                {
                    maxdiff = abs(boletos[i]-boletos[x]);
                    if(boletos[i] < boletos[x])
                    {
                        a = boletos[i];
                        b = boletos[x];
                    }
                    else
                    {
                        a = boletos[i];
                        b = boletos[x];
                    }
                }
            }
        }
    }
    cout << a << " " << b << endl;
}

int main()
{
    int cases;
    cin >> cases;
    int nboletos, dconseguido, temp;
    vector<int> boletos(100000);
    while(cases--)
    {
        boletos.clear();
        cin >> nboletos;
        for(int i = 0; i < nboletos; i++)
        {
            cin >> temp;
            boletos[i] = temp;
        }
        cin >> dconseguido;
        conseguirBoletos(dconseguido,boletos,nboletos);
    }
    return 0;
}