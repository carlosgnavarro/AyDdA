#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPerfectSquare(int n) {
    if (n < 0) return false;
    int root = round(sqrt(n));
    return n == root * root;
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        int num_pegs;
        cin >> num_pegs;

        vector<int> pegs(num_pegs, 0);
        int disk_count = 0;

        for (int disk = 1; ; ++disk) {
            bool placed = false;
            for (int i = 0; i < num_pegs; ++i) {
                if (pegs[i] == 0 || isPerfectSquare(pegs[i] + disk)) {
                    pegs[i] = disk;
                    placed = true;
                    disk_count++;
                    break;
                }
            }
            if (!placed) break;
        }

        cout << disk_count << endl;
    }

    return 0;
}