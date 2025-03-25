#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Este problema implica maximizar el descuento total que se puede obtener al comprar artículos 
en una tienda. Es un buen ejemplo de cómo los algoritmos voraces pueden usarse para resolver 
problemas de optimización que involucran descuentos*/

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> prices(n);
        for (int i = 0; i < n; ++i) {
            cin >> prices[i];
        }
        sort(prices.begin(), prices.end(), greater<long long>());
        long long discount = 0;
        for (int i = 2; i < n; i += 3) {
            discount += prices[i];
        }
        cout << discount << endl;
    }
    return 0;
}