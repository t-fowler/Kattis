#include <iostream>
#include <string>
#include <vector>

//
// Given an R x C matrix of characters, enlarge the matrix such that each character
// is substituted by a zR x zC sub-matrix where all entries are the same character.
//

std::string _expandRow(std::string row, std::string accumulator, int zC) {
    if (row == "") {
        return accumulator;
    }
    accumulator += std::string(zC, row[0]);
    return _expandRow(row.substr(1, row.size()), accumulator, zC);
}

std::string expandRow(std::string row, int zC) {
    return _expandRow(row, "", zC);
}

int main() {
    int R, C, zR, zC;
    std::cin >> R >> C >> zR >> zC >> std::ws;

    std::vector<std::string> inputLines;
    std::vector<std::string> outputLines;

    for (int i = 0; i < R; ++i) {
        std::string line;
        std::getline(std::cin, line);
        inputLines.push_back(line);
    }
    
    for (int row = 0; row < R; ++row) {
        for (int i = 0; i < zR; ++i) {
            outputLines.push_back(expandRow(inputLines[row], zC));
        }
    }

    for (auto line : outputLines) {
        std::cout << line << std::endl;
    }
}