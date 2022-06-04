#include <iostream>

//
// Divide M teams into N rooms.
// Input: N, M
// Output: N lines with the number of teams in the corresponding room.
//

void printStars(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << '*';
    }
    std::cout << std::endl;
}

int main() {
    int N, M, quotient, remainder;
    std::cin >> N >> M;
    quotient = M / N;
    remainder = M % N;

    for (int i = 0; i < N; i++) {
        if (i < remainder) {
            printStars(quotient + 1);
        } else {
            printStars(quotient);
        }
    }
}