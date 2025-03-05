#include <iostream>

using namespace std;

int main()
{
    int length, n_gas;
    vector<pair<int,int>> gas;
    while(cin >> length >> n_gas && (length != 0 && n_gas != 0))
    {
        int x,r;
        cin >> x >> r;
        gas.push_back(make_pair(x-r,x+r));
        sort(gas.begin(),gas.end());
        int position = 0;
        while(position < length)
        {
            
        }
    }
    return 0;
}