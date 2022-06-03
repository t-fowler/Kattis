#include <iostream>
#include <string>

//
// Input: up to 100 characters of names, separated by hyphens.
// Output: the acronym of the input names.
//

int main() {
    std::string input;
    std::string output;
    int delimiterIndex;

    std::getline(std::cin, input);
    input.push_back('-');

    while ((delimiterIndex = input.find('-')) != -1) {
        output.push_back(input.substr(0, delimiterIndex)[0]);
        input.erase(0, delimiterIndex + 1);
    }

    std::cout << output << std::endl;
}