#include <iostream>

using namespace std;

int main()
{
    // pI = Marca indicadora, tD = Grados totales, pA-C = Posiciones del dial 1,2 y 3
    int pI,tD,pA,pB,pC,temp;
    while(cin >> pI >> pA >> pB >> pC)
    {
        if(pI == 0 && pA == 0 && pB == 0 && pC == 0)
        {
            break;
        }
        tD = 720;
        if(pI >= pA)
        {
            tD += (pI-pA)*9;
        }
        else
        {
            tD += (40-(pA-pI))*9;
        }
        tD += 360;
        if(pB >= pA)
        {
            tD += (pB-pA)*9;
        }
        else
        {
            tD += (40-(pA-pB))*9;
        }
        if(pB >= pC)
        {
            tD += (pB-pC)*9;
        }
        else
        {
            tD += (40-(pC-pB))*9;
        }
        cout << tD << endl;
    }
    return 0;
}