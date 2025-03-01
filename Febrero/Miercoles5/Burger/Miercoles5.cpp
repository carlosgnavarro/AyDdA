#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a;
    string b;
    int D_index = 3000000, R_index = 3000000;
    int d;
    cin >> a;
    while(a != 0)
    {
        cin >> b;
        for(int i = 0; i < a; i++)
        {
            d = 3000000;
            if(b[i] == 'Z')
            {

                d = 0;
                break; 
            }
            if(b[i] == 'R' || b[i] == 'D')
            {
                if(b[i] == 'R')
                {
                    R_index = i;
                }
                if(b[i] == 'D')
                {
                    D_index = i;
                }
                if(abs(R_index-D_index) < d)
                {
                    d = abs(R_index-D_index);
                }
            }
        }
        cout << d << endl;
        cin >> a;
    }
    return 0;
}