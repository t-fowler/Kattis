#ifndef KNIGHTSFEN_H
#define KNIGHTSFEN_H

#include <array>
#include <utility>

enum Piece {
    WHITE_KNIGHT,
    BLACK_KNIGHT,
    EMPTY
};

typedef std::array<Piece, 25> Board;
typedef std::pair<int, int> Move;

void print_position(Board b);
Board parse_position();
bool is_valid_square(int idx);

#endif