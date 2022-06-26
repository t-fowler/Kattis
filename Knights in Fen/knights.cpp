#include <array>
#include <iostream>
#include <string>

enum Piece {
    WHITE_KNIGHT,
    BLACK_KNIGHT,
    EMPTY
};

typedef std::array<std::array<Piece, 5>, 5> Board;

void print_position(Board b) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j != 0)
                std::cout << " ";
            std::cerr << b[i][j]; 
        }
        std::cerr << std::endl;
    }
}

Board parse_position() {
    Board board = {EMPTY};
    for (int i = 0; i < 5; i++) {
        std::string line;
        std::getline(std::cin, line);
        //std::cerr << line << std::endl;
        
        int j = 0;
        for (char c : line) {
            //std::cerr << line[j];
            if (c == ' ') {
                board[i][j++] = EMPTY;
            } else if (c == '0') {
                board[i][j++] = WHITE_KNIGHT;
            } else if (c == '1') {
                board[i][j++] = BLACK_KNIGHT;
            }
            
        }
        //std::cerr << std::endl;
    }
    return board;
}

int main() {
    int N;
    std::cin >> N;
    std::cin.get();
    for (int i = 0; i < N; i++) {
        Board board = parse_position();
        print_position(board);
        std::cerr << std::endl;
    }
}