#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        string s;
        cin >> s;

        int vowel_count = 0;
        int consonant_count = 0;

        for (char c : s) {
            if (isVowel(c)) {
                vowel_count++;
            } else {
                consonant_count++;
            }
        }

        double vowel_ratio = (double)vowel_count / s.length();
        double consonant_ratio = (double)consonant_count / s.length();

        if (vowel_ratio > 0.3 && consonant_ratio > 0.6) {
            cout << "hard" << endl;
        } else {
            cout << "easy" << endl;
        }
    }

    return 0;
}