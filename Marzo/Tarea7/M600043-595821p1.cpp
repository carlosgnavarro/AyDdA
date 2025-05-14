#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int k;
    cin >> k;

    while (k--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 0; j <= n; ++j) 
            {
                for (int digit = 0; digit <= 9; ++digit) 
                {
                    if (digit <= j) 
                    {
                        dp[i][j] += dp[i - 1][j - digit];
                    }
                }
            }
        }

        cout << dp[n][n] << endl;
    }

    return 0;
}