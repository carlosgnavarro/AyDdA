#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void kombiFinden(int maxKapazitatInicial, int maxKapazitatRestante, const vector<int>& gewicht, int index, vector<int>& aktuellKombi, int& maxLaden, vector<int>& besteKombi) {
    if (index == gewicht.size()) {
        int aktuellLaden = maxKapazitatInicial - maxKapazitatRestante;
        if (aktuellLaden > maxLaden) {
            maxLaden = aktuellLaden;
            besteKombi = aktuellKombi;
        } else if (aktuellLaden == maxLaden) {
            if (aktuellLaden > 0) { 
                bool besser = false;
                size_t k = 0;
                while (k < aktuellKombi.size() && k < besteKombi.size()) {
                    auto aktuellIt = find(gewicht.begin(), gewicht.end(), aktuellKombi[k]);
                    auto besserIt = find(gewicht.begin(), gewicht.end(), besteKombi[k]);
                    if (distance(gewicht.begin(), aktuellIt) < distance(gewicht.begin(), besserIt)) {
                        besser = true;
                        break;
                    } else if (distance(gewicht.begin(), aktuellIt) > distance(gewicht.begin(), besserIt)) {
                        break;
                    }
                    k++;
                }
                if (besser) {
                    besteKombi = aktuellKombi;
                }
            }
        }
        return;
    }
    kombiFinden(maxKapazitatInicial, maxKapazitatRestante, gewicht, index + 1, aktuellKombi, maxLaden, besteKombi);
    if (maxKapazitatRestante >= gewicht[index]) {
        vector<int> neuKombi = aktuellKombi;
        neuKombi.push_back(gewicht[index]);
        kombiFinden(maxKapazitatInicial, maxKapazitatRestante - gewicht[index], gewicht, index + 1, neuKombi, maxLaden, besteKombi);
    }
}

void bootLaden(int maxKapazitat, const vector<int>& gewicht) {
    int maxLaden = 0;
    vector<int> besteKombi;
    vector<int> aktuellKombi;
    kombiFinden(maxKapazitat, maxKapazitat, gewicht, 0, aktuellKombi, maxLaden, besteKombi);
    cout << maxLaden << " =";
    for (size_t i = 0; i < besteKombi.size(); ++i) {
        cout << " " << besteKombi[i];
    }
    cout << endl;
}

int main() 
{
    int maxKapazitat, nContainers;
    while (cin >> maxKapazitat >> nContainers && (maxKapazitat != 0 || nContainers != 0)) {
        vector<int> gewicht(nContainers);
        for (int i = 0; i < nContainers; ++i) {
            cin >> gewicht[i];
        }
        bootLaden(maxKapazitat, gewicht);
    }
    return 0;
}