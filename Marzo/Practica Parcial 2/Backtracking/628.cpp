#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<string> dictionary;
    string word;

    while (cin >> n) {
        dictionary.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> dictionary[i];
        }

        int m;
        cin >> m;
        vector<string> patterns(m);
        for (int i = 0; i < m; ++i) {
            cin >> patterns[i];
        }

        cout << "--" << endl;

        for (const string& pattern : patterns) {
            function<void(int, string)> generate = [&](int index, string current) {
                if (index == pattern.length()) {
                    cout << current << endl;
                    return;
                }

                if (pattern[index] == '#') {
                    for (int i = 0; i < n; ++i) {
                        generate(index + 1, current + dictionary[i]);
                    }
                } else {
                    generate(index + 1, current + pattern[index]);
                }
            };

            generate(0, "");
        }
    }

    return 0;
}