#ifndef KNIGHTSINFENSOLVER_H
#define KNIGHTSINFENSOLVER_H

#include <memory>
#include <vector>
#include "knightsfen.hpp"

/*
 * A node class for the search tree.
 */
class Node {   
private:     
    std::shared_ptr<Node> parent;
    Board position;
    Move appliedMove;

public:
    Node(Board position);
    Node(std::shared_ptr<Node> parent, Board position, Move move);

    int getCost(); // Number of moves from the initial position.
    Node getParent();
    Board getPosition();
    Move getAppliedMove();
};

/*
 * A solver class for the Knights in Fen problem.
 */
class KnightsInFenSolver {
private:
    Board initial;
    Board goal;

    std::vector<Move> moves(Board position); // All moves that are legal in the given position.
    Board makeMove(Board position, Move move); // Get the position after makeing the move.
    std::vector<std::shared_ptr<Node>> expand(std::shared_ptr<Node> node); // Expand the search tree with children of node.

public:
    KnightsInFenSolver(Board initial);

    int heuristic(Board position);
    int solve();
};

#endif