#include <iostream>

//
// What size frame is needed to fit a list of windows if they are
// added in the given order and moved to the next line when adding
// would make the frame greater than some maximum width?
//

int main() {
    int x = 0;
    int y = 0;

    int current_x = 0;
    int current_y = 0;

    int m = -1;
    std::cin >> m;
    do {
        while (true) {
            int window_x = 0, window_y = 0;
            std::cin >> window_x >> window_y;
            if (window_x == -1 && window_y == -1)
                break;

            if (current_x + window_x <= m) {
                current_x += window_x;
                if (current_x > x) x = current_x;
                if (window_y > current_y) current_y = window_y;
            } else {
                current_x = window_x;
                y += current_y;
                current_y = window_y;
            }
        }
        y += current_y;

        std::cout << x << " x " << y << std::endl;
        x = 0; y = 0;
        current_x = 0; current_y = 0;
        std::cin >> m;
    } while (m != 0);
}