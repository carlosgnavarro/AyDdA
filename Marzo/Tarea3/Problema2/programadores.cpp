#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int, int>> programmers;
    int n_programmers;
    while(cin >> n_programmers && n_programmers != 0)
    {
        programmers.clear();
        for(int i = 0; i < n_programmers; i++)
        {
            int I, T;
            cin >> I >> T;
            programmers.push_back({I, T});
        }
        sort(programmers.begin(), programmers.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });
        int tiempo_total = 0;
        int current_time = 0;
        for(auto &programmer : programmers)
        {
            current_time += programmer.first;
            tiempo_total = max(tiempo_total, current_time + programmer.second); 
        }
        cout << tiempo_total << endl;
    }
    return 0;
}