#include <iostream>

//
// Start by printing 1 or 2. Then read from standard input then alternate
// reading and writing numbers that are increasing by 1 or 2 each time.
// Win by printing the number 99. Must exit if 99 is printed or read.
//

int main() {
    int x = 0;
    int acc = 1;
    do {
        if (x % 3 == 2) {
            x += 1;
        } else if (x % 3 == 1) {
            x += 2;
        } else {
            x += acc + 1;
            acc = !acc;
        }
        std::cout << x << std::endl;
        if (x == 99) 
            return 0;
        std::cin >> x;
    } while (x < 99);
}