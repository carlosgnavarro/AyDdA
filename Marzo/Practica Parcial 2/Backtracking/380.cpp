#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ForwardingRule {
    int start_time;
    int duration;
    int forwarding_number;
};

int main() {
    int case_num = 1;
    int n;

    while (cin >> n && n != 0) {
        map<int, vector<ForwardingRule>> forwarding_rules;

        for (int i = 0; i < n; ++i) {
            int phone_number, start_time, duration, forwarding_number;
            cin >> phone_number >> start_time >> duration >> forwarding_number;
            forwarding_rules[phone_number].push_back({start_time, duration, forwarding_number});
        }

        cout << "SYSTEM " << case_num++ << endl;

        int call_time, calling_number, called_number;
        while (cin >> call_time >> calling_number >> called_number && call_time != 0) {
            int final_number = called_number;
            vector<int> visited; 
            
            while (true) {
                bool forwarded = false;
                visited.push_back(final_number);

                if (forwarding_rules.count(final_number)) {
                    for (const auto& rule : forwarding_rules[final_number]) {
                        if (call_time >= rule.start_time && call_time < rule.start_time + rule.duration) {
                            final_number = rule.forwarding_number;
                            forwarded = true;

                            bool loop = false;
                            for (int v : visited) {
                                if (v == final_number) {
                                    loop = true;
                                    break;
                                }
                            }
                            if (loop) {
                                final_number = 9999;
                            }

                            break; 
                        }
                    }
                }
                if (!forwarded) break;
            }
            cout << "AT " << call_time << " CALL FROM " << calling_number << " TO " << called_number << " ENDS AT " << final_number << endl;
        }
        cout << endl;
    }

    return 0;
}