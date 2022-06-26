#include <iostream>
#include <string>

#include "knightsfen.hpp"
#include "KnightsInFen.hpp"

void print_position(Board b) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j != 0)
                std::cout << " ";
            std::cerr << b[5*i + j]; 
        }
        std::cerr << std::endl;
    }
}

Board parse_position() {
    Board position = {EMPTY};
    for (int i = 0; i < 5; i++) {
        std::string line;
        std::getline(std::cin >> std::ws, line);
        //std::cerr << line << std::endl;
        
        int j = 0;
        for (char c : line) {
            //std::cerr << line[j];
            if (c == ' ') {
                position[5*i + j++] = EMPTY;
            } else if (c == '0') {
                position[5*i + j++] = WHITE_KNIGHT;
            } else if (c == '1') {
                position[5*i + j++] = BLACK_KNIGHT;
            }
            
        }
        //std::cerr << std::endl;
    }
    return position;
}

bool is_valid_square(int idx) {
    return (idx >= 0 && idx < 25);
}

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int minimumNumberOfMoves = -1;
        Board board = parse_position();
        //print_position(board);
        //std::cerr << std::endl;

        KnightsInFen problem(board);
        minimumNumberOfMoves = problem.solve();
        if (minimumNumberOfMoves < 0) {
            std::cout << "Unsolvable in less than 11 move(s)." << std::endl;
        } else {
            std::cout << "Solvable in " << minimumNumberOfMoves << " move(s)." << std::endl;
        }
    }
}