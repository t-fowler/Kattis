#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

int det(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}

int main() {
    std::cout << std::setprecision(1) << std::fixed;
    int n_vertices;
    std::cin >> n_vertices;

    while (n_vertices != 0) {
        std::vector<int> xs;
        std::vector<int> ys;

        for (int i = 0; i < n_vertices; i++) {
            int x, y;
            std::cin >> x >> y;
            xs.push_back(x);
            ys.push_back(y);
        }

        // accumulate area from the vertices.
        int doubled_area = 0;
        int j = n_vertices - 1;
        for(int i = 0; i < n_vertices; i++) {
            doubled_area += det(xs[i], ys[i], xs[j], ys[j]);
            j = i;
        }

        if (doubled_area < 0) {
            std::cout << "CCW " << -doubled_area / 2.0 << std::endl;
        } else {
            std::cout << "CW " << doubled_area / 2.0 << std::endl;
        }

        std::cin >> n_vertices;
    }
}