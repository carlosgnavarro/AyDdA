#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Este problema implica emparejar caballeros con dragones para derrotarlos, 
minimizando el costo total. Es un buen ejemplo de cómo los algoritmos voraces pueden 
usarse para resolver problemas de optimización que involucran emparejamiento*/

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<int> heads(n);
        vector<int> knights(m);

        for (int i = 0; i < n; ++i) {
            cin >> heads[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> knights[i];
        }

        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());

        int gold = 0;
        int headIndex = 0;
        int knightIndex = 0;

        while (headIndex < n && knightIndex < m) {
            if (knights[knightIndex] >= heads[headIndex]) {
                gold += knights[knightIndex];
                headIndex++;
            }
            knightIndex++;
        }

        if (headIndex == n) {
            cout << gold << endl;
        } else {
            cout << "Loowater is doomed!" << endl;
        }
    }
    return 0;
}