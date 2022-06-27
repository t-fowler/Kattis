#ifndef KNIGHTSINFENSOLVER_H
#define KNIGHTSINFENSOLVER_H

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
    std::shared_ptr<Node> getParent() const;
    Board getPosition() const;
    Move getAppliedMove() const;
};

class KnightsInFenSolver {
private:
    Board initial;
    Board goal;

    std::vector<Move> moves(Board position);
    Board makeMove(Board position, Move move);
    std::vector<std::shared_ptr<Node>> expand(std::shared_ptr<Node> node);
public:
    KnightsInFenSolver(Board initial);
    int solve();
};

#endif