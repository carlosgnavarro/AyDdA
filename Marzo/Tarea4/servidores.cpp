#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int computerserver,kapazitat,kosten,morgenaufgaben,abendaufgaben,zusatkosten;
    vector<int> morgenaufgabenvector,abendaufgabenvector;
    while(cin >> computerserver >> kapazitat >> kosten && ((computerserver != 0) && (kapazitat != 0) && (kosten != 0)))
    {
        for(int i = 0; i < computerserver; i++)
        {
            cin >> morgenaufgaben;
            morgenaufgabenvector.push_back(morgenaufgaben);
        }
        for(int i = 0; i < computerserver; i++)
        {
            cin >> abendaufgaben;
            abendaufgabenvector.push_back(abendaufgaben);
        }
        sort(morgenaufgabenvector.begin(), morgenaufgabenvector.end());
        sort(abendaufgabenvector.begin(), abendaufgabenvector.end());
        zusatkosten = 0;
        for(int i = 0; i < computerserver; i++)
        {
            zusatkosten +=  (morgenaufgabenvector[i] + abendaufgabenvector[computerserver - i - 1] - kapazitat) * kosten;
        }
        if(zusatkosten > 0)
        {
            cout << zusatkosten << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        morgenaufgabenvector.clear();
        abendaufgabenvector.clear();
    }
    return 0;
}