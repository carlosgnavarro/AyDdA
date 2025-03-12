#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long vergleich(pair<long long, long long>& a, pair<long long, long long>& b)
{
    return a.first + a.second < b.first + b.second;
}

int main()
{
    int computerserver,kapazitat,kosten;
    while(cin >> computerserver >> kapazitat >> kosten && (computerserver != 0 && kapazitat != 0 && kosten != 0))
    {
        vector<long long> morgenaufgaben(computerserver),abendaufgaben(computerserver);
        for(int i = 0; i < computerserver; i++)
        {
            cin >> morgenaufgaben[i];
        }
        for(int i = 0; i < computerserver; i++)
        {
            cin >> abendaufgaben[i];
        }
        vector<pair<long long, long long>> aufgaben;
        for (int i = 0; i < computerserver; i++) {
            aufgaben.push_back(make_pair(morgenaufgaben[i], abendaufgaben[i]));
        }
        sort(aufgaben.begin(), aufgaben.end(),vergleich);
        long long zusatkosten = 0;
        for (const auto& proceso : aufgaben) {
            if (proceso.first + proceso.second > kapazitat) {
                zusatkosten += (proceso.first + proceso.second - kapazitat) * kosten;
            }
        }
        if(zusatkosten > 0)
        {
            cout << zusatkosten << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}