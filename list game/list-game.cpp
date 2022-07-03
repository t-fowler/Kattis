#include <iostream>
#include <cmath>

//
// Given a positive integers X, find a list of positive integers [y_1 .. y_k] such that
// (y_1 + 1) * (y_2 + 1) * ... * (y_k + 1) = X. What is the largest number k that this
// is possible?
//

int countPrimeFactors(int X) {
    int primes = 0;
    for (int i = 2; i <= std::sqrt(X); ++i) {
        while (X % i == 0) {
            ++primes;
            X = X / i;
        }
    }
    if (X >= 2)
        ++primes;

    return primes;
}

int main() {
    int X = 0;
    std::cin >> X;
    std::cout << countPrimeFactors(X) << std::endl;
}