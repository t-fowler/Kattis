#include <iostream>
#include <vector>
#include <utility>

// Returns the square number for the given file and rank of
// a chessboard. File must be an ascii character between 'A' and 'H' inclusive.
// Rank must be an integer between 1 and 8 inclusive.
int enumerateSquare(char file, int rank) {
    return 8 * (rank - 1) + (file - 65);
}

// Reverse of enumerateSquare.
void indexToSquare(int index, char &file, int &rank) {
    file = index % 8 + 65;
    rank = index / 8 + 1;
}

// Determines if the file and rank are a valid square on a chessboard.
bool isValidSquare(char file, int rank) {
    return (file >= 'A' && file <= 'H' && rank >= 1 && rank <=8);
}

// Determines if the move from start square to destination square is a valid bishop move.
bool isValidMove(char startFile, int startRank, char destinationFile, int destinationRank) {
    if (!isValidSquare(startFile, startRank) || 
        !isValidSquare(destinationFile, destinationRank)) {
            return false;
    }
    int fileDistance = std::abs(destinationFile - startFile);
    int rankDistance = std::abs(destinationRank - startRank);

    return (fileDistance == rankDistance && fileDistance != 0);
}

// Produces the required output for the given set of moves.
void generateOutput(std::vector<std::pair<char, int>> moves) {
    std::cout << moves.size() - 1;
    for (auto move : moves) {
        std::cout << " " << move.first << " " << move.second;
    }
    std::cout << std::endl;
}

int main() {
    int inputSize;
    std::cin >> inputSize;

    for (int i = 0; i < inputSize; i++) {
        char startFile, destinationFile;
        int startRank, destinationRank;

        std::cin >> startFile >> startRank
                >> destinationFile >> destinationRank;
        //std::cerr << "Start: " << startFile << startRank << " idx: " << enumerateSquare(startFile, startRank)
        //        << " End: " << destinationFile << destinationRank << " idx: " << enumerateSquare(destinationFile, destinationRank)
        //        << std::endl;

        // Check if destination is same colour square as start.
        // If it is not, then the test case is impossible.
        if ((enumerateSquare(startFile, startRank) + startRank) % 2 != 
            (enumerateSquare(destinationFile, destinationRank) + destinationRank) % 2) {
                //std::cerr << startFile << " " << destinationFile << " " 
                //        << startRank << " " << destinationRank << std::endl;
                std::cout << "Impossible" << std::endl;
                continue;
        }

        std::vector<std::pair<char, int>> moveList;
        std::vector<std::pair<char, int>> reachable;
        moveList.push_back(std::make_pair(startFile, startRank));

        if (startFile == destinationFile && startRank == destinationRank) {
            generateOutput(moveList);
            continue;
        }

        bool destinationReached = false;
        for (int i = 0; i < 64; i++) {
            char iFile;
            int iRank;
            indexToSquare(i, iFile, iRank);
            if (isValidMove(startFile, startRank, iFile, iRank)) {
                if (iFile == destinationFile && iRank == destinationRank) {
                    moveList.push_back(std::make_pair(destinationFile, destinationRank));
                    generateOutput(moveList);
                    destinationReached = true;
                    break;
                } else {
                    reachable.push_back(std::make_pair(iFile, iRank));
                }
            } 
        }

        if (!destinationReached) {
            for (auto square : reachable) {
                //std::cerr << square.first << " " << square.second << std::endl;
                if (isValidMove(square.first, square.second, destinationFile, destinationRank)) {
                    moveList.push_back(square);
                    moveList.push_back(std::make_pair(destinationFile, destinationRank));
                    generateOutput(moveList);
                    break;
                }
            }
        }

    }
}