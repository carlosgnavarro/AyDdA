#include <iostream>
#include <vector>

using namespace std;

void caminosdecatan(int nodo_actual, int (*catan)[25], int nodos, int longitud)
{
    for(int i = 0; i < nodos; i++)
    {
        if(catan[nodo_actual][i] == 1)
        {
            catan[nodo_actual][i] = 2;
            catan[i][nodo_actual] = 2;
            longitud++;
            caminosdecatan(i,catan,nodos,longitud);
            
        }
    }
}

int main()
{
    int nodos, aristas;
    int catan[25][25];
    cin >> nodos >> aristas;
    for(int i = 0; i < aristas; i++)
    {
        int a,b;
        cin >> a >> b;
        catan[a][b] = 1;
        catan[b][a] = 1;
    }
    return 0;
}