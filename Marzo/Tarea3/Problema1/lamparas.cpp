#include <iostream>

using namespace std;

void lamparas(int n, string calzada)
{
    char calle[n];
    for (int i = 0; i < n; i++)
    {
        if(calzada[i] == '-')
        {
            calle[i] = '-';
            if(i > 0 and i < n-1)
            {
                calle[i-1] = '-';
                calle[i+1] = '-';
            }
            if(i == 0 and n != 1)
            {
                calle[i+1] = '-';
            }
            if(i == n-1 and n != 1)
            {
                calle[i-1] = '-';
            }
        }
        else
        {
            calle[i] = '+';
        }
    }
}

int main()
{
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; i++)
    {
        int n;
        cin >> n;
        string calzada;
        cin >> calzada;
        cout << calzada << endl;
    }
    return 0;
}