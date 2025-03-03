#include <iostream>
#include <vector>

using namespace std;

bool comparar(pair<int,int> x, pair<int,int> y)
{
    return x.second > y.second;
}

int main()
{
    vector<pair<int, int>> programadores;
    int n_programmers;
    while(cin >> n_programmers && n_programmers != 0)
    {
        programadores.clear();
        for(int i = 0; i < n_programmers; i++)
        {
            int I, T;
            cin >> I >> T;
            programadores.push_back({I, T});
        }
        sort(programadores.begin(), programadores.end(),comparar);
        int total = 0;
        int temp = 0;
        for(int i = 0; i < programadores.size(); i++)
        {
            temp += programadores[i].first;
            total = max(total, temp + programadores[i].second); 
        }
        cout << total << endl;
    }
    return 0;
}