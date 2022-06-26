#ifndef KNIGHTSINFEN_H
#define KNIGHTSINFEN_H

#include <memory>
#include <vector>
#include "knightsfen.hpp"

class Node {   
private:     
    std::shared_ptr<Node> parent;
    Board position;
    Move appliedMove;
public:
    Node(Board position);
    Node(std::shared_ptr<Node> parent, Board position, Move move);

    Node& operator=(const Node &other);

    int getCost() const;
    Node getParent() const;
    Board getPosition() const;
    Move getAppliedMove() const;
};

class KnightsInFen {
private:
    Board initial;
    Board goal;

    std::vector<Move> moves(Board position);
    Board makeMove(Board position, Move move);
    std::vector<Node> expand(std::shared_ptr<Node> node);
public:
    KnightsInFen(Board initial);
    int solve();
};

#endif