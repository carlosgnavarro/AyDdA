#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

int compare(const tuple<int, int, double>& a, const tuple<int, int, double>& b) {
    return get<2>(a) > get<2>(b);
}

int main()
{
    int computerserver, kapazitat, mehrkosten;
    while(cin >> computerserver >> kapazitat >> mehrkosten && (computerserver != 0 && kapazitat != 0 && mehrkosten != 0))
    {
        vector<int> morgenaufgaben(computerserver);
        vector<int> abendaufgaben(computerserver);

        for(int i = 0; i < computerserver; i++)
        {
            cin >> morgenaufgaben[i];
        }
        for(int i = 0; i < computerserver; i++)
        {
            cin >> abendaufgaben[i];
        }

        vector<tuple<int, int, int>> aufgabenpaare;
        for(int i = 0; i < computerserver; i++)
        {
            for(int j = 0; j < computerserver; j++)
            {
                double kombiniertedruck = (morgenaufgaben[i] / kapazitat) + (abendaufgaben[j] / kapazitat);
                aufgabenpaare.emplace_back(i, j, kombiniertedruck);
            }
        }

        sort(aufgabenpaare.begin(), aufgabenpaare.end(), compare);

        vector<bool> morgenzugewiesen(computerserver, false);
        vector<bool> abendzugewiesen(computerserver, false);

        vector<pair<int, int>> zuteilungen;

        for(const auto& tp : aufgabenpaare)
        {
            int m_index = get<0>(tp);
            int a_index = get<1>(tp);

            if(!morgenzugewiesen[m_index] && !abendzugewiesen[a_index])
            {
                zuteilungen.push_back({m_index, a_index});
                morgenzugewiesen[m_index] = true;
                abendzugewiesen[a_index] = true;
            }
        }

        vector<int> nichtzugewiesenmorgen;
        vector<int> nichtzugewiesenabend;

        for(int i = 0; i < computerserver; i++)
        {
            if(!morgenzugewiesen[i])
            {
                nichtzugewiesenmorgen.push_back(i);
            }
            if(!abendzugewiesen[i])
            {
                nichtzugewiesenabend.push_back(i);
            }
        }

        sort(nichtzugewiesenmorgen.begin(), nichtzugewiesenmorgen.end(), [&](int a, int b) {
            return morgenaufgaben[a] > morgenaufgaben[b];
        });
        sort(nichtzugewiesenabend.begin(), nichtzugewiesenabend.end(), [&](int a, int b) {
            return abendaufgaben[a] > abendaufgaben[b];
        });

        int nichtzugeweisenum = min(nichtzugewiesenmorgen.size(), nichtzugewiesenabend.size());
        for(int i = 0; i < nichtzugeweisenum; i++)
        {
            zuteilungen.push_back({nichtzugewiesenmorgen[i], nichtzugewiesenabend[i]});
        }

        double mehrkostenbetrag = 0;
        for(const auto& z : zuteilungen)
        {
            int m_index = z.first;
            int a_index = z.second;
            double total_load = morgenaufgaben[m_index] + abendaufgaben[a_index];
            double druck = max(0.0, total_load - kapazitat);
            mehrkostenbetrag += druck * mehrkosten;
        }
        cout << round(mehrkostenbetrag) << endl;
    }
    return 0;
}