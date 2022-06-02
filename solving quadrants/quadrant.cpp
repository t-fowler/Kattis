#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;

    int ans;
    if (x > 0) {
        if (y > 0) ans = 1;
        else ans = 4;
    }
    else if (y > 0) {
        ans = 2;
    }
    else {
        ans = 3;
    }

    std::cout << ans;
}