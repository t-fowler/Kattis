#include <iostream>
#include <array>
#include <string>

bool isValidSquare(int i, int j) {
    return (i >= 0 && i < 7 && j >=0 && j < 7);
}

int countMovesToSquare(std::array<std::string, 7> board, int i, int j) {
    int moveCount = 0;
    // Up direction.
    if (isValidSquare(i-2, j) && board[i-1][j] == 'o' && board[i-2][j] == 'o') {
        ++moveCount;
    }
    // Down direction
    if (isValidSquare(i+2, j) && board[i+1][j] == 'o' && board[i+2][j] == 'o') {
        ++moveCount;
    }
    // Left direction
    if (isValidSquare(i, j-2) && board[i][j-1] == 'o' && board[i][j-2] == 'o') {
        ++moveCount;
    }
    // Right direction
    if (isValidSquare(i, j+2) && board[i][j+1] == 'o' && board[i][j+2] == 'o') {
        ++moveCount;
    }
    return moveCount;
}

int main() {
    std::array<std::string, 7> pegBoard;
    for (int i = 0; i < pegBoard.size(); ++i) {
        std::getline(std::cin, pegBoard[i]);
    }

    int moveCount = 0;
    for (int i = 0; i < pegBoard.size(); ++i) {
        for (int j = 0; j < pegBoard[i].size(); ++j) {
            if (pegBoard[i][j] == '.') { // For all empty squares on the board.
                moveCount += countMovesToSquare(pegBoard, i, j);
            }
        }
    }

    std::cout << moveCount << std::endl;
}