#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // servidores, capacidad, costo, tareas matutinas, tareas vespertinas, costo adicional respectivamente
    int computerserver,kapazitat,kosten;
    while(cin >> computerserver >> kapazitat >> kosten && (computerserver != 0 && kapazitat != 0 && kosten != 0))
    {
        vector<long long> morgenaufgaben(computerserver),abendaufgaben(computerserver);
        // relleno de vector de tareas matutinas
        for(int i = 0; i < computerserver; i++)
        {
            cin >> morgenaufgaben[i];
        }
        // relleno de vector de tareas vespertinas
        for(int i = 0; i < computerserver; i++)
        {
            cin >> abendaufgaben[i];
        }
        // Combine the morning and evening tasks into a single vector of pairs
        std::vector<std::pair<long long, long long>> tasks;
        for (int i = 0; i < computerserver; i++) {
            tasks.push_back(std::make_pair(morgenaufgaben[i], abendaufgaben[i]));
        }
        
        // Sort the tasks based on their combined cost
        std::sort(tasks.begin(), tasks.end(), [](const std::pair<long long, long long>& a, const std::pair<long long, long long>& b) {
            return a.first + a.second < b.first + b.second;
        });
        
        // Assign the tasks to the servers using a greedy algorithm
        long long zusatkosten = 0;
        std::vector<std::pair<long long, long long>> optimalPairs;
        for (const auto& task : tasks) {
            if (task.first + task.second > kapazitat) {
                zusatkosten += (task.first + task.second - kapazitat) * kosten;
            }
            optimalPairs.push_back(task);
        }
        
        // Print out the optimal pairs
        std::cout << "Optimal pairs:" << std::endl;
        for (const auto& pair : optimalPairs) {
            std::cout << "Morning task: " << pair.first << ", Evening task: " << pair.second << std::endl;
        }
        
        // Print out the additional cost
        std::cout << "Additional cost: " << zusatkosten << std::endl;
        if(zusatkosten > 0)
        {
            cout << zusatkosten << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}