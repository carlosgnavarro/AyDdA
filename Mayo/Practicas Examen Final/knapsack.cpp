#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solveKnapsack(const vector<int>& values, const vector<int>& weights, int maxWeight) 
{
    int numItems = values.size();
    vector<vector<int>> blek(numItems + 1, vector<int>(maxWeight + 1, 0));
    for (int i = 1; i <= numItems; ++i) 
    {
        for (int w = 1; w <= maxWeight; ++w) 
        {
            if (weights[i - 1] > w) 
            {
                blek[i][w] = blek[i - 1][w];
            } 
            else 
            {
                blek[i][w] = max(blek[i - 1][w], values[i - 1] + blek[i - 1][w - weights[i - 1]]);
            }
        }
    }
    return blek[numItems][maxWeight];
}

int main() 
{
    int numTestCases;
    cin >> numTestCases;

    while (numTestCases--) 
    {
        int numItems;
        cin >> numItems;

        vector<int> values(numItems);
        vector<int> weights(numItems);

        for (int i = 0; i < numItems; ++i) 
        {
            cin >> values[i] >> weights[i];
        }

        int numPeople;
        cin >> numPeople;

        vector<int> maxWeights(numPeople);
        for (int i = 0; i < numPeople; ++i) 
        {
            cin >> maxWeights[i];
        }

        int totalValue = 0;
        
        for (int maxWeight : maxWeights) 
        {
            totalValue += solveKnapsack(values, weights, maxWeight);
        }

        cout << totalValue << endl;
    }

    return 0;
}