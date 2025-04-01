#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<string> board;
set<string> found_words;
vector<vector<bool>> visited;

// Function to check if a word is in the dictionary (replace with your dictionary lookup)
bool isInDictionary(const string& word) {
    // Replace this with your actual dictionary lookup
    // For example, you could use a set or a trie data structure
    // to store the dictionary and efficiently check if the word exists.
    return false; // Placeholder
}

void dfs(int row, int col, string current_word) {
    current_word += board[row][col];

    if (current_word.length() >= 3 && isInDictionary(current_word)) {
        found_words.insert(current_word);
    }

    visited[row][col] = true;

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int new_row = row + dr[i];
        int new_col = col + dc[i];

        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n && !visited[new_row][new_col]) {
            dfs(new_row, new_col, current_word);
        }
    }

    visited[row][col] = false; // Backtrack
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        cin >> n;
        board.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
            transform(board[i].begin(), board[i].end(), board[i].begin(), ::toupper); // Convert to uppercase
        }

        found_words.clear();
        visited.assign(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j, "");
            }
        }

        vector<string> sorted_words(found_words.begin(), found_words.end());
        sort(sorted_words.begin(), sorted_words.end());

        for (const string& word : sorted_words) {
            cout << word << endl;
        }

        if (num_test_cases > 0) {
            cout << endl;
        }
    }

    return 0;
}