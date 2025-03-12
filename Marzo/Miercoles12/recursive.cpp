#include <iostream>
#include <cmath>

using namespace std;

vector<int> x;

void factorial(vector<int> &v, int x)
{
    int carry = 0; 
    for(int i = 0; i < v.size(); i++)
    {
        int digit_product = v[i]*x + carry;
        carry = digit_product / 10;
        v[i] = (digit_product % 10);
    }
    while(carry)
    {
        v.push_back(carry % 10); 
        carry /= 10;
    }
}

int mcd(int a, int b)
{
    if (b == 0)
    {
        return a;        
    }
    else
    {
        return mcd(b, a%b);
    }
}

int main()
{
   cout << mcd(252,105) << endl;
    x.push_back(1);
    for(int i = 2; i <= 100; i++)
    {
        factorial(x,i);
    }
    reverse(x.begin(),x.end());
    for(auto i : x)
    {
        cout << i;
    }
    return 0;
}