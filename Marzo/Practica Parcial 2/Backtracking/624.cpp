#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int tape_length, num_tracks;

    while (cin >> tape_length) {
        cin >> num_tracks;
        vector<int> track_lengths(num_tracks);

        for (int i = 0; i < num_tracks; ++i) {
            cin >> track_lengths[i];
        }

        vector<bool> include_track(num_tracks, false);
        vector<bool> best_tracks(num_tracks, false);
        int max_sum = 0;

        function<void(int, int)> solve = [&](int index, int current_sum) {
            if (index == num_tracks) {
                if (current_sum <= tape_length && current_sum > max_sum) {
                    max_sum = current_sum;
                    best_tracks = include_track;
                }
                return;
            }

            // Option 1: Exclude the current track
            solve(index + 1, current_sum);

            // Option 2: Include the current track
            include_track[index] = true;
            solve(index + 1, current_sum + track_lengths[index]);
            include_track[index] = false; // Backtrack
        };

        solve(0, 0);

        for (int i = 0; i < num_tracks; ++i) {
            if (best_tracks[i]) {
                cout << track_lengths[i] << " ";
            }
        }

        cout << "sum:" << max_sum << endl;
    }

    return 0;
}