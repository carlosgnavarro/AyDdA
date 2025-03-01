#include <iostream>
#include <string>
using namespace std;

int count_carry(string a, string b)
{
    int carry = 0, count = 0;
    int len_a = a.length(), len_b = b.length();
    while (len_a != 0 || len_b != 0) {
        int x = 0, y = 0;
        if (len_a > 0) {
            x = a[len_a - 1] - '0';
            len_a--;
        }
        if (len_b > 0) {
            y = b[len_b - 1] - '0';
            len_b--;
        }
        int sum = x + y + carry;
        if (sum >= 10) {
            carry = 1;
            count++;
        }
        else
            carry = 0;
    }
    return count;
}

int main()
{
    string a,b;
    cin >> a >> b;
    while(a != "0" && b != "0")
    {
        if(count_carry(a,b) == 0)
        {
            cout << "Sin acarreos" << endl;
        }
        else if(count_carry(a,b) == 1)
        {
            cout << count_carry(a,b) << " acarreo" << endl;
        }
        else
        {
            cout << count_carry(a,b) << " acarreos" << endl;
        }
        cin >> a >> b;
    }
    return 0;
}