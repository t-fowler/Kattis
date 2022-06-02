#include <iostream>
#include <vector>

int main() {
    int N;
    std::vector<int> vec;
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        vec.push_back(x);
    }
    while (!vec.empty()) {
        std::cout << vec.back() << std::endl;
        vec.pop_back();
    }
}