#include <iostream>

using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        int n, k;
        cin >> n >> k;

        if (k >= n) {
            cout << factorial(n) << endl;
        } else {
            long long result = 1;
            for (int i = 0; i < k; ++i) {
                result *= (n - i);
            }
            cout << result << endl;
        }
    }

    return 0;
}