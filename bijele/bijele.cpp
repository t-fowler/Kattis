#include<iostream>

//
// Input: 6 integers on a single line between 0 and 10 (inclusive).
//        They represent (in order) the number of kings, queens, rooks, bishops,
//        knights, and pawns that are in Mirko's set of white chess pieces.
//
// Output: 6 integers on a lingle line which are the number of each type of piece
//         that Mirko should add or remove to have the proper amount.
//

int main() {
    int input;
    

    // One king.
    std::cin >> input;
    std::cout << 1 - input;

    // One queen.
    std::cin >> input;
    std::cout << " " << 1 - input;

    // Two rooks and minor pieces.
    for (int i = 0; i < 3; i++) {
        std::cin >> input;
        std::cout << " " << 2 - input;
    }

    // Eight pawns.
    std::cin >> input;
    std::cout << " " << 8 - input << std::endl;
    
}