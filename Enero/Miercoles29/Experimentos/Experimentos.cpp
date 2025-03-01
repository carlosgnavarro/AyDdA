#include <iostream>
#include <string>
using namespace std;

int main()
{
    int cases;
    string code;
    cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        cin >> code;
        int size = code.length();
        if(code == "1" || code == "78" || code == "4")
        {
            cout << "+" << endl;
        }
        else
        {
            if(code[size-1] == '5' && code[size-2] == '3')
            {
                cout << "-" << endl;
            }
            else if(code[0] == '9' && code[size-1] == '4')
            {
                cout << "*" << endl;
            }
            else if(code[0] == '1' && code[1] == '9' && code[2] == '0')
            {
                cout << "?" << endl;
            }
            else
            {
                cout << "?" << endl;
            }
        }
    }
    return 0;
}