#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

vector<vector<int>> soluciones;

bool seguro(const vector<int>& pos, int fila, int col) {
    for (int c = 0; c < col; ++c) {
        int f = pos[c];
        if (f == fila || abs(f - fila) == abs(c - col))
            return false;
    }
    return true;
}


void reinas(int col, vector<int>& pos) {
    if (col == pos.size()) {
        soluciones.push_back(pos);
        return;
    }
    for (int fila = 0; fila < pos.size(); fila++) {
        if (seguro(pos, fila, col)) {
            pos[col] = fila;
            reinas(col + 1, pos);
        }
    }
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            int r;
            cin >> r;
            v[i] = r - 1; 
        }

        soluciones.clear();
        vector<int> pos(n);
        reinas(0, pos);

        int min_movs = n;
        for (int i = 0; i < soluciones.size(); ++i) {
            int movs = 0;
            for (int j = 0; j < n; ++j) {
                if (soluciones[i][j] != v[j])
                    movs++;
            }
            min_movs = min(min_movs, movs);
        }        

        cout << min_movs << endl;
    }

    return 0;
}
