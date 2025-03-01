#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    long int l = 0,sum = 1;
    int digit = 1;
    vector<long int> S(32001);
    vector<long int>::iterator i;

    for(int s = 1; s < 32000; s++)
    {
        digit = log10(s)+1;
        l+=digit;
        sum+=l;
        S[s] = sum;
    }
    i = lower_bound(S.begin(),S.end(),123456);
    i--;
    cout << *i << " " << i-S.begin();
    return 0;
}