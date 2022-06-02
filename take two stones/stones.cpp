#include <iostream>

// Alice and Bob in turns take exactly two consecutive stones on the ground until
// there are no consecutive stones on the ground. That is, each player can take
// stone 𝑖 and stone 𝑖+1, where 1≤𝑖≤𝑁−1. If the number of stone left is odd, Alice
// wins. Otherwise, Bob wins.

int main() {
    int N;
    std::cin >> N;

    if (N % 2) std::cout << "Alice"
    else  std::cout << "Bob"
}