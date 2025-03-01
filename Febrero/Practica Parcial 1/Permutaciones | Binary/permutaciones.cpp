#include <iostream>

using namespace std;

vector<int> permutations;
vector<int> levels;

void construir_arboles(int left, int right, int d)
{
    int largest = -1, largest_index = -1;
    for(int i = left; i <= right; i++)
    {
        if(permutations[i] > largest)
        {
            largest_index = i;
            largest = permutations[i];
        }
    }
    levels[largest_index] = d;
    if(left < largest_index)
    {
        construir_arboles(left,largest_index-1,d+1);
    }
    if(right > largest_index)
    {
        construir_arboles(largest_index+1,right,d+1);
    }
}

int main()
{
    int cases,permutation_length,temp;
    cin >> cases;
    while(cases--)
    {
        permutations.clear();
        permutations.resize(permutation_length);
        cin >> permutation_length;
        for(int i = 0; i < permutation_length; i++)
        {
            cin >> temp;
            permutations[i] = temp;
        }
        levels.clear();
        levels.resize(permutation_length);
        construir_arboles(0,permutation_length-1,0);
        for(int i = 0; i < permutation_length; i++)
        {
            cout << levels[i] << " ";
        }
        cout << endl;
    }
    return 0;
}