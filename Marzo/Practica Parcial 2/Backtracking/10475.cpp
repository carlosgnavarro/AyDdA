#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool shareCommonChar(const string& word1, const string& word2) {
    for (char c1 : word1) {
        for (char c2 : word2) {
            if (c1 == c2) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    for (int case_num = 1; case_num <= num_test_cases; ++case_num) {
        int num_words, num_keywords;
        cin >> num_words >> num_keywords;

        vector<string> words(num_words);
        for (int i = 0; i < num_words; ++i) {
            cin >> words[i];
            transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
        }

        vector<string> keywords(num_keywords);
        for (int i = 0; i < num_keywords; ++i) {
            cin >> keywords[i];
            transform(keywords[i].begin(), keywords[i].end(), keywords[i].begin(), ::tolower);
        }

        vector<int> dp(num_keywords, 1);
        vector<int> prev(num_keywords, -1);

        int max_len = 0;
        int end_index = -1;

        for (int i = 0; i < num_keywords; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!shareCommonChar(keywords[i], keywords[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }

            if (dp[i] > max_len) {
                max_len = dp[i];
                end_index = i;
            }
        }

        cout << "Case " << case_num << ": " << max_len << endl;

        if (end_index != -1) {
            vector<string> result;
            int curr = end_index;
            while (curr != -1) {
                result.push_back(keywords[curr]);
                curr = prev[curr];
            }

            for (int i = result.size() - 1; i >= 0; --i) {
                cout << result[i] << (i == 0 ? "" : " ");
            }
            cout << endl;
        }
    }

    return 0;
}