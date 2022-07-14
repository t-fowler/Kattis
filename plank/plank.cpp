#include <iostream>

//
// Given a length n: 1 <= n <= 24, how many ways can you combine planks
// of size 1, 2, and 3 to create a plank of length n?
//

int numberOfPlankCombinations(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n == 3) {
        return 4;
    }

    return numberOfPlankCombinations(n - 1) + numberOfPlankCombinations(n - 2) + numberOfPlankCombinations(n - 3);
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << numberOfPlankCombinations(n) << std::endl;
}