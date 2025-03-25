#include <iostream>
#include <string>

using namespace std;

/*Este problema implica verificar si una cadena es una subsecuencia de otra. 
Se puede resolver utilizando un enfoque voraz simple, lo que lo convierte en un 
buen ejercicio para principiantes*/

int main() {
    string s, t;
    while (cin >> s >> t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        if (i == s.length()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}