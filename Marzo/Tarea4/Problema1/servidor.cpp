#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int server, kapazitat, extrakosten;
    while(cin >> server >> kapazitat >> extrakosten && (server != 0 && kapazitat != 0 && extrakosten != 0))
    {
        vector<int> morgaufgaben(server);
        vector<int> abenaufgaben(server);
        for(int i = 0; i < server; i++)
        {
            cin >> morgaufgaben[i];
        }
        for(int i = 0; i < server; i++)
        {
            cin >> abenaufgaben[i];
        }
        sort(morgaufgaben.begin(), morgaufgaben.end());
        sort(abenaufgaben.begin(), abenaufgaben.end(),greater<int>());
        int mindkosten = 0;
        for (int i = 0; i < server; ++i) {
            int gesamntladen = morgaufgaben[i] + abenaufgaben[i];
            int uberladen = max(0, gesamntladen - kapazitat);
            mindkosten += uberladen * extrakosten;
        }
        cout << mindkosten << endl;
    }
}