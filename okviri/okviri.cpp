#include <iostream>
#include <string>

void appendWendyFrame(std::string *output, char c) {
    output[0] = output[0].substr(0,  output[0].size() - 1);
    output[1] = output[1].substr(0,  output[1].size() - 1);
    output[2] = output[2].substr(0,  output[2].size() - 1);
    output[3] = output[3].substr(0,  output[3].size() - 1);
    output[4] = output[4].substr(0,  output[4].size() - 1);
    
    output[0] += "..*..";
    output[1] += ".*.*.";
    output[2] += "*.";
    output[2] += c;
    output[2] += ".*";
    output[3] += ".*.*.";
    output[4] += "..*..";
}

void appendPeterPanFrame(std::string *output, char c) {
     output[0] += ".#..";
    output[1] += "#.#.";
    output[2] += ".";
    output[2] += c;
    output[2] += ".#";
    output[3] += "#.#.";
    output[4] += ".#..";
}

int main() {
    std::string input;
    std::string output[5];
    std::cin >> input;

    output[0] += "..#..";
    output[1] += ".#.#.";
    output[2] += "#.";
    output[2] += input[0];
    output[2] += ".#";
    output[3] += ".#.#.";
    output[4] += "..#..";

    for (int i = 1; i < input.size(); ++i) {
        if (i % 3 == 2) { // Wendy frame.
            appendWendyFrame(output, input[i]);
        } else { // Peter Pan frame.
           appendPeterPanFrame(output, input[i]);
        }
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << output[i] << std::endl;
    }
}