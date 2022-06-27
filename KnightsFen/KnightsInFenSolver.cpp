#include <algorithm>
#include <iostream>
#include <queue>
#include "KnightsInFenSolver.hpp"

Node::Node(Board position) {
    this->parent = NULL;
    this->position = position;
    this->appliedMove = std::make_pair(-1, -1);
}

Node::Node(std::shared_ptr<Node> parent, Board position, Move move) {
    this->parent = parent;
    this->position = position;
    this->appliedMove = move;
}

int Node::getCost() {
    if (parent == NULL) {
        return 0;
    }
    return parent->getCost() + 1;
}

Node Node::getParent() {
    return *parent;
}

Board Node::getPosition() {
    return position;
}

Move Node::getAppliedMove() {
    return appliedMove;
}

//
// Finds the empty square on the board (assumes only one). Returns a list
// of all the valid knight moves by filtering out moves that would go off
// the 5x5 board.
//
std::vector<Move> KnightsInFenSolver::moves(Board position) {
    std::vector<Move> result;
    int emptySquare = -1;
    for (int i = 0; i < position.size(); i++) {
        if (position[i] == EMPTY)
            emptySquare = i;
    }

    int file = emptySquare % 5;
    int rank = emptySquare / 5;
    // Up-up-left
    if (file >= 1 && rank >= 2) {
        result.push_back(std::make_pair(emptySquare, emptySquare - 11));
    }
    // Up-left-left
    if(file >= 2 && rank >= 1) {
        result.push_back(std::make_pair(emptySquare, emptySquare - 7));
    }
    // Up-up-right
    if(file <= 3 && rank >= 2) {
        result.push_back(std::make_pair(emptySquare, emptySquare - 9));
    }
    // Up-right-right
    if(file <= 2 && rank >= 1) {
        result.push_back(std::make_pair(emptySquare, emptySquare - 3));
    }
    // Down-down-left
    if(file >= 1 && rank <= 2) {
        result.push_back(std::make_pair(emptySquare, emptySquare + 9));
    }
    // Down-left-left
    if(file >= 2 && rank <= 3) {
        result.push_back(std::make_pair(emptySquare, emptySquare + 3));
    }
    // Down-down-right
    if(file <= 3 && rank <= 2) {
        result.push_back(std::make_pair(emptySquare, emptySquare + 11));
    }
    // down-right-right
    if(file <= 2 && rank <= 3) {
        result.push_back(std::make_pair(emptySquare, emptySquare + 7));
    }

    for (auto move : result) {
        if (move.first < 0 || move.first > 24 || 
            move.second < 0 || move.second > 24)
                std::cerr << "Error in moves: " << emptySquare << std::endl;
    }

    return result;
}

Board KnightsInFenSolver::makeMove(Board position, Move move) {
    Piece movePiece = position[move.second];
    position[move.first] = movePiece;
    position[move.second] = EMPTY;
    
    return position;
}

//
// Creates the child nodes by applying all the legal moves to the node's
// position. 
//
std::vector<std::shared_ptr<Node>> 
KnightsInFenSolver::expand(std::shared_ptr<Node> node) {
    std::vector<std::shared_ptr<Node>> result;
    Board position = node->getPosition();
    for(Move move : moves(position)) {
        result.push_back(std::shared_ptr<Node>(new Node(node, makeMove(position, move), move)));
    }
    return result;
}

KnightsInFenSolver::KnightsInFenSolver(Board initial) {
    this->initial = initial;
    this->goal = {
        BLACK_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT,
        WHITE_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT,
        WHITE_KNIGHT, WHITE_KNIGHT, EMPTY, BLACK_KNIGHT, BLACK_KNIGHT,
        WHITE_KNIGHT, WHITE_KNIGHT, WHITE_KNIGHT, WHITE_KNIGHT, BLACK_KNIGHT,
        WHITE_KNIGHT, WHITE_KNIGHT, WHITE_KNIGHT, WHITE_KNIGHT, WHITE_KNIGHT
    };
}

//
// Determines how many pieces are in incorrect positions.
//
int KnightsInFenSolver::heuristic(Board position) {
    int numberOfIncorrectPieces = 0;
    for (int i = 0; i < 25; i++) {
        if (position[i] != EMPTY && position[i] != goal[i])
            ++numberOfIncorrectPieces;
    }
    return numberOfIncorrectPieces;
}

//
// Solves the search problem using the A* algorithm with the above heuristic.
//
int KnightsInFenSolver::solve() {
    auto compare = [&](std::shared_ptr<Node> left, std::shared_ptr<Node> right) {
        return (left->getCost() + heuristic(left->getPosition())) 
            > (right->getCost() + heuristic(right->getPosition()));
    };
    std::priority_queue<
        std::shared_ptr<Node>, 
        std::vector<std::shared_ptr<Node>>, 
        decltype(compare)> 
    frontier(compare);
    frontier.push(std::shared_ptr<Node>(new Node(initial)));
    if (frontier.top()->getPosition() == goal)
        return 0;

    std::vector<Board> reached;
    reached.push_back(initial);

    while(!frontier.empty()) {
        std::shared_ptr<Node> node = frontier.top();
        frontier.pop();

        if (node->getCost() > 10) {
            return -1;
        }

        auto possibleMoves = expand(node);
        for (auto child : possibleMoves) {
            if (child->getPosition() == goal) {
                //std::cerr << "SUCCESS!!!" << std::endl;
                return child->getCost();
            }
            if (std::find(reached.begin(), reached.end(), child->getPosition()) == reached.end()) {
                reached.push_back(child->getPosition());
                frontier.push(child);
            }
        }
    }

    return -1;
}