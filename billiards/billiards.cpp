#include <iostream>
#include <iomanip>
#include <cmath>

//
// Consider a billiard ball being shot from the middle of the table. Given the length of each side
// of the table (a and b), the amount of time for the ball to return to the middle (s) and the number
// of times the ball bounces off the horizontal and vertical sides of the table (m and n); determine the
// angle that the ball was shot measured from horizontal in degrees, and the velocity of the ball assuming
// no loss of energy.
//
// Input: a - the horizontal length in inches, 
//        b - the vertical length in inches, 
//        s - the time in seconds for the ball to return to the centre, 
//        m - the number of times the ball bounces off the vertical edge, 
//        n - the number of times the ball bounces off the horizontal edge
//
// Output: A - the angle in degrees that the ball was shot at (0 to 90 inclusive)
//         v - the (constant) velocity of the ball.

int main() {
    std::cout << std::setprecision(2) << std::fixed;
    int a = -1, b = -1, s = -1, m = -1, n = -1;
    
    while (true) {
        std::cin >> a >> b >> s >> m >> n;

        if (a == 0 && b == 0 && s == 0 && m == 0 && n == 0)
            break;

        long verticalDistance = b * n;
        long horizontalDistance = a * m;

        double inchesTravelled 
        = std::sqrt(verticalDistance * verticalDistance + 
                    horizontalDistance * horizontalDistance);

        double inchesPerSecond = inchesTravelled / s;
        double angleInDegrees = std::acos(horizontalDistance / inchesTravelled) 
                                * 180 / (2 * std::acos(0.0));

        std::cout << angleInDegrees << " " << inchesPerSecond << std::endl;
    }
}