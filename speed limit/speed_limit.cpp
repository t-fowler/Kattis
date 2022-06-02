#include <iostream>

//
// Input is formatted as the number (n) of which there are datapoints in the set,
// followed by n datapoints containing the the speed (in mph) and the time on the
// stopwatch (in hours from the start of the dataset) when the speed was changed.
// -1 is used to denote the end of the data.
//
// Outputs the total amount of miles travelled in each dataset.
//
// Ex.
// 3
// 20 2
// 30 6
// 10 7
// 2
// 60 1
// 30 5
// -1
//

int main() {
    int n;
    std::cin >> n;
    while (n != -1) {
        int total_miles = 0;
        int total_time = 0;
        for (int i = 0; i < n; i++) {
            int speed_mph;
            int current_time;
            std::cin >> speed_mph >> current_time;
            total_miles += speed_mph * (current_time - total_time);
            total_time = current_time;
        }
        std::cout << total_miles << " miles" << std::endl;
        std::cin >> n;
    }
}