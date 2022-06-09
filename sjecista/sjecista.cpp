#include <iostream>
//
// Consider a convex polygon with N vertices, with the additional property
// that *no three diagonals intersect* in a single point. Find the number of
// intersections between pairs of diagonals in such a polygon.
//

int main() {
    int N;
    std::cin >> N;
    std::cout << N*(N-1)*(N-2)*(N-3)/24 << std::endl;
}