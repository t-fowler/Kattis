#include<iostream>
#include<complex>
#include<cmath>

//
// Determine whether the given complex number is in the mandelbrot set.
//

typedef std::complex<long double> complex;

bool mandelbrot(complex zN, complex c, int maxIterations) {
    if (std::norm(zN) > 4.0)
        return false;
    if (maxIterations == 0)
        return true;
    return mandelbrot(zN * zN + c, c, maxIterations - 1);
}

int main() {
    for (int i = 0; i < 15; ++i) {
        if ((std::cin >> std::ws).eof()) {
            std::cerr << "end of file." << std::endl;
            break;
        } else {
            double realPart, imaginaryPart;
            int maxIterations;
            std::cin >> realPart >> imaginaryPart >> maxIterations;
            if (mandelbrot(0, complex(realPart, imaginaryPart), maxIterations)) {
                std::cout << "Case " << i+1 << ": IN" << std::endl;
            } else {
                std::cout << "Case " << i+1 << ": OUT" << std::endl;
            }
        }
    } 
}