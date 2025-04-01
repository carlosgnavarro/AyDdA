#include <iostream>

using namespace std;

int factorial(int n)
{
    int result = 1;
    for(int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int L;
    while(true)
    {
        cin >> L;
        if(!L)
        {
            return 0;
        }
        int length = 0;
        for(int n = 1; n <= L; n++)
        {
            length += factorial(L) / factorial(L-n);
        }
        cout << length << endl;
    }
    return 0;
}