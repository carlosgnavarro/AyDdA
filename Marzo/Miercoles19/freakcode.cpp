#include <iostream>
#include <vector>
#include <cstddef>
#include <string>

using namespace std;

bool posible(string cadena, char c)
{
    
    int position = cadena.find_last_of(c);
    while(position != string::npos)
    {
        bool valido = false;
        int a = cadena.size() - 1;
        int b = position - 1;
        for(int i = 0; !valido and (b-i) > 0 and (a-i) > position; i--)
        {
            if(cadena[i] == cadena[position-i])
            {
                valido = true;
            }
            if(valido == false)
            {
                return false;
            }
            position = cadena.find_last_of(c,position-1);   
        }
    }
    return true;
}

void freak(int n, int L, int count, string &cadena)
{
    if(count == n)
    {
        cout << cadena;
        return;
    }
    for(char c = 'A'; c < 'A' + L; c++)
    {
        if(posible(cadena,c))
        {
            cadena.push_back(c);
            freak(n,L,count++,cadena);
            cadena.pop_back();
        }
    }
}

int main()
{
    int n,L;
    while(true)
    {
        cin >> n >> L;
        if(!n && !L)
        {
            return 0;
        }
        int count = 0;
        string cadena;
        freak(n,L,count,cadena);
    }
    return 0;
}