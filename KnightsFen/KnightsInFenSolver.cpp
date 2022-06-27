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

int Node::getCost() const {
    if (parent == NULL) {
        return 0;
    }
    return parent->getCost() + 1;
}

std::shared_ptr<Node> Node::getParent() const {
    return parent;
}

Board Node::getPosition() const {
    return position;
}

Move Node::getAppliedMove() const {
    return appliedMove;
}

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
        if (move.first < 0 || move.first > 24 || move.second < 0 || move.second > 24)
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

std::vector<std::shared_ptr<Node>> KnightsInFenSolver::expand(std::shared_ptr<Node> node) {
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

int KnightsInFenSolver::solve() {
    std::shared_ptr<Node> root = std::shared_ptr<Node>(new Node(initial));
    if (root->getPosition() == goal) return 0;

    std::queue<std::shared_ptr<Node>> frontier;
    frontier.push(root);

    std::vector<Board> reached;
    reached.push_back(initial);

    while(!frontier.empty()) {
        std::shared_ptr<Node> node = frontier.front();
        frontier.pop();

        //print_position(node->getPosition());

        //std::cerr << node->getCost() << std::endl;
        if (node->getCost() > 10) {
            //std::cerr << "Too deep." << std::endl;
            return -1;
        }

        auto possibleMoves = expand(node);
        for (auto child : possibleMoves) {
            //std::cerr << child->getCost() << std::endl;
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