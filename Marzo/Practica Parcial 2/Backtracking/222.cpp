#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    double capacity, distance, initial_cost;
    double mpg;

    while (cin >> capacity >> distance >> mpg >> initial_cost) {
        int num_stations;
        cin >> num_stations;

        vector<pair<double, double>> stations(num_stations); // distance, price
        for (int i = 0; i < num_stations; ++i) {
            cin >> stations[i].first >> stations[i].second;
        }

        stations.push_back({distance, 0.0}); // Add destination as a station

        double current_fuel = 0.0;
        double current_position = 0.0;
        double total_cost = initial_cost;

        for (int i = 0; i <= num_stations; ++i) {
            double next_station_distance = stations[i].first;
            double next_station_price = stations[i].second;

            double distance_to_next = next_station_distance - current_position;
            double fuel_needed = distance_to_next / mpg;

            if (fuel_needed > capacity) {
                total_cost = -1.0; // Impossible to reach
                break;
            }

            // Check if it's cheaper to fill up now or later
            int j = i + 1;
            while (j <= num_stations) {
                double next_next_distance = stations[j].first;
                double distance_to_next_next = next_next_distance - current_position;
                double fuel_needed_next_next = distance_to_next_next / mpg;

                if (fuel_needed_next_next > capacity) break; // Can't reach

                if (stations[j].second <= next_station_price) {
                    // Cheaper station found
                    break;
                }
                j++;
            }

            double fill_amount = 0.0;
            if (j <= num_stations && stations[j].second <= next_station_price) {
                // Fill up only enough to reach the cheaper station
                double distance_to_cheaper = stations[j].first - current_position;
                double fuel_needed_cheaper = distance_to_cheaper / mpg;
                fill_amount = max(0.0, fuel_needed_cheaper - current_fuel);
            } else {
                // Fill up completely
                fill_amount = capacity - current_fuel;
            }

            total_cost += fill_amount * (next_station_price / 100.0);
            current_fuel += fill_amount;
            current_fuel -= fuel_needed;
            current_position = next_station_distance;
        }

        if (total_cost == -1.0) {
            cout << "Impossible" << endl;
        } else {
            cout << fixed << setprecision(2) << total_cost << endl;
        }
    }

    return 0;
}