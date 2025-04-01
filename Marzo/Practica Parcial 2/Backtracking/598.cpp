#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int num_test_cases;
    cin >> num_test_cases;
    cin.ignore(); // Consume the newline character after reading the number of test cases
    cin.ignore(); // Consume the blank line after the number of test cases

    while (num_test_cases--) {
        vector<string> lines;
        string line;

        while (getline(cin, line) && !line.empty()) {
            lines.push_back(line);
        }

        string range_str;
        getline(cin, range_str);

        int start_index, end_index;
        size_t dash_pos = range_str.find('-');

        if (dash_pos == string::npos) {
            // Single index
            stringstream ss(range_str);
            ss >> start_index;
            end_index = start_index;
        } else {
            // Range of indices
            stringstream ss1(range_str.substr(0, dash_pos));
            stringstream ss2(range_str.substr(dash_pos + 1));
            ss1 >> start_index;
            ss2 >> end_index;
        }

        if (start_index < 1) start_index = 1;
        if (end_index > lines.size()) end_index = lines.size();

        if (start_index > end_index || start_index > lines.size()) {
            cout << "Empty" << endl;
        } else {
            for (int i = start_index - 1; i < end_index; ++i) {
                cout << lines[i] << endl;
            }
        }

        if (num_test_cases > 0) {
            cout << endl;
        }
    }

    return 0;
}