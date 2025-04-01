#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(vector<int>& nums, int index, int current_value) {
    if (index == 5) {
        return current_value == 23;
    }

    return solve(nums, index + 1, current_value + nums[index]) ||
           solve(nums, index + 1, current_value - nums[index]) ||
           solve(nums, index + 1, current_value * nums[index]);
}

int main() {
    vector<int> nums(5);

    while (cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4] &&
           !(nums[0] == 0 && nums[1] == 0 && nums[2] == 0 && nums[3] == 0 && nums[4] == 0)) {

        sort(nums.begin(), nums.end());
        bool possible = false;

        do {
            possible = solve(nums, 1, nums[0]);
            if (possible) break;
        } while (next_permutation(nums.begin(), nums.end()));

        cout << (possible ? "Possible" : "Impossible") << endl;
    }

    return 0;
}