#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main() {
    int capacity_a, capacity_b, target;

    while (cin >> capacity_a >> capacity_b >> target) {
        map<pair<int, int>, string> visited;
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[{0, 0}] = "";

        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            if (a == target || b == target) {
                cout << visited[{a, b}];
                cout << "success" << endl;
                break;
            }

            // Fill A
            if (visited.find({capacity_a, b}) == visited.end()) {
                visited[{capacity_a, b}] = visited[{a, b}] + "fill A\n";
                q.push({capacity_a, b});
            }

            // Fill B
            if (visited.find({a, capacity_b}) == visited.end()) {
                visited[{a, capacity_b}] = visited[{a, b}] + "fill B\n";
                q.push({a, capacity_b});
            }

            // Empty A
            if (visited.find({0, b}) == visited.end()) {
                visited[{0, b}] = visited[{a, b}] + "empty A\n";
                q.push({0, b});
            }

            // Empty B
            if (visited.find({a, 0}) == visited.end()) {
                visited[{a, 0}] = visited[{a, b}] + "empty B\n";
                q.push({a, 0});
            }

            // Pour A to B
            int pour_a_to_b = min(a, capacity_b - b);
            if (visited.find({a - pour_a_to_b, b + pour_a_to_b}) == visited.end()) {
                visited[{a - pour_a_to_b, b + pour_a_to_b}] = visited[{a, b}] + "pour A B\n";
                q.push({a - pour_a_to_b, b + pour_a_to_b});
            }

            // Pour B to A
            int pour_b_to_a = min(b, capacity_a - a);
            if (visited.find({a + pour_b_to_a, b - pour_b_to_a}) == visited.end()) {
                visited[{a + pour_b_to_a, b - pour_b_to_a}] = visited[{a, b}] + "pour B A\n";
                q.push({a + pour_b_to_a, b - pour_b_to_a});
            }
        }
    }

    return 0;
}