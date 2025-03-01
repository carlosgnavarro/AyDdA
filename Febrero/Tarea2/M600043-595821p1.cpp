#include <iostream>
#include <vector>

using namespace std;

bool puedeConstruir(int objetivo, vector<int>& tubos) {
    int n = tubos.size();
    vector<bool> dp(objetivo + 1, false);
    dp[0] = true;  

    for (int tubo : tubos) {
        for (int j = objetivo; j >= tubo; j--) {
            if (dp[j - tubo]) {
                dp[j] = true;
            }
        }
    }

    return dp[objetivo];
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int objetivo, numTubos;
        cin >> objetivo >> numTubos;
        vector<int> tubos(numTubos);
        for (int i = 0; i < numTubos; ++i) {
            cin >> tubos[i];
        }

        if(puedeConstruir(objetivo,tubos)){
            cout << "SI" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}


