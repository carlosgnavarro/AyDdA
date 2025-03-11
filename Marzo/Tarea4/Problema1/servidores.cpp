#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int computerservers, kapazitat, kosten;
    while(cin >> computerservers >> kapazitat >> kosten && (computerservers != 0 && kapazitat != 0 && kosten != 0))
    {
        vector<int> morgenaufgaben(computerservers);
        for(int i = 0; i < computerservers; i++)
        {
            cin >> morgenaufgaben[i];
        }
        vector<int> abendaufgaben(computerservers);
        for(int i = 0; i < computerservers; i++)
        {
            cin >> abendaufgaben[i];
        }
        vector<int> aufgaben = morgenaufgaben;
        aufgaben.insert(aufgaben.end(), abendaufgaben.begin(), abendaufgaben.end());
        sort(aufgaben.begin(), aufgaben.end());
        vector<int> last(computerservers,0);
        int zusatkosten = 0;
        for(int aufgaben : aufgaben)
        {
            int midex = min_element(last.begin(), last.end()) - last.begin();
            last[midex] += aufgaben;
            if(last[midex] > kapazitat)
            {
                zusatkosten += (last[midex] - kapazitat) * kosten;
            }
        }
        cout << zusatkosten << endl;
    }
    return 0;
}