#include <iostream>

using namespace std;

int main()
{
    int casos,n,k;
    cin >> casos;
    while(casos--)
    {
        cin >> n >> k;
        int mul = n+1, sum = 0, cur = 1;
        while(n >= k)
        {
            if(n & 1)
            {
                sum += cur;
            }
            n >>= 1;
            cur <<= 1;
        }
        cout << mul * sum / 2 << endl;
    }
    return 0;
}