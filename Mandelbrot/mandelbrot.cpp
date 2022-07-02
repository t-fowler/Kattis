#include<iostream>
#include<complex>
#include<cmath>

//
// Determine whether the given complex number is in the mandelbrot set.
//

typedef std::complex<double> complex;

complex complexSquared(complex c) {
    return complex(
            c.real() * c.real() - c.imag() * c.imag(),
            2 * c.real() * c.imag());
}

double complexModulus(complex c) {
    return std::sqrt(c.real() * c.real() +
                    c.imag() * c.imag());
}

bool mandelbrot(complex accumulator, complex c, int maxIterations) {
    complex zN = complexSquared(accumulator) + c;
    if (complexModulus(zN) > 2.0)
        return false;
    if (maxIterations == 0)
        return true;
    return mandelbrot(zN, c, maxIterations - 1);
}

int main() {
    for (int i = 0; i < 15; ++i) {
        if ((std::cin >> std::ws).eof()) {
            break;
        } else {
            double realPart, imaginaryPart;
            int maxIterations;
            std::cin >> realPart >> imaginaryPart >> maxIterations;
            if (mandelbrot(0, complex(realPart, imaginaryPart), maxIterations - 1)) {
                std::cout << "Case " << i+1 << ": IN" << std::endl;
            } else {
                std::cout << "Case " << i+1 << ": OUT" << std::endl;
            }
        }
    } 
}