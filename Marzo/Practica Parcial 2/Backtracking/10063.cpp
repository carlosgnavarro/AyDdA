#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    bool first_case = true;

    while (cin >> input) {
        if (!first_case) {
            cout << endl;
        }
        first_case = false;

        vector<string> permutations;
        permutations.push_back(string(1, input[0]));

        for (size_t i = 1; i < input.length(); ++i) {
            vector<string> new_permutations;
            for (const string& perm : permutations) {
                for (size_t j = 0; j <= perm.length(); ++j) {
                    string new_perm = perm;
                    new_perm.insert(j, 1, input[i]);
                    new_permutations.push_back(new_perm);
                }
            }
            permutations = new_permutations;
        }

        for (const string& perm : permutations) {
            cout << perm << endl;
        }
    }

    return 0;
}