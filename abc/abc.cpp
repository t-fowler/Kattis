#include <iostream>

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void insertion_sort(int &A, int &B, int &C) {
    if (A > B && A > C) {
        swap(A, C);
        if (A > B) {
            swap (A, B);
        }
    } else if (A > B)  {
        swap(A, B);
    } else if (A > C) {
        swap(A, C);
        swap(B, C);
    } else if (B > C) {
        swap (B, C);
    }
}

int main() {
    int A, B, C;
    std::cin >> A >> B >> C >> std::ws;

    insertion_sort(A, B, C);

    for (int i = 0; i < 3; ++i) {
        char c;
        std::cin >> c;
        if (c == 'A') {
            std::cout << A;
        } else if (c == 'B') {
            std::cout << B;
        } else if (c == 'C') {
            std::cout << C;
        }

        if (i == 2) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }
}