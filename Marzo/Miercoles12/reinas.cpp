#include <iostream>

using namespace std;

int tablero[8][8]={0};

bool amenaza(int fila, int columna)
{
    for(int c = 0; c < columna; c++)
    {
        if(tablero[fila][c] == 1)
        {
            return true;
        }
    }
    for(int c = columna-1, f = fila -1; c >= 0 && f >= 0; f--, c--)
    {
        if(tablero[f][c] == 1)
        {
            return true;
        }
    }
    for(int c = columna-1, f = fila + 1; c >= 0 && f <= 7; f++, c--)
    {
        if(tablero[f][c] == 1)
        {
            return true;
        }
    }
    return false;
}


void reinas(int columna)
{
    if(columna == 8)
    {
        for(int f = 0; f < 8; f++)
        {
            for(int c = 0; c < 8; c++)
            {
                cout << tablero[f][c];
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    for(int fila = 0; fila < 8; fila++)
    {
        if(!amenaza(fila,columna))
        {
            tablero[fila][columna] = 1;
            reinas(columna+1);
            tablero[fila][columna] = 0;
        }
    }
}

int main()
{
    reinas(0);
    return 0;
}