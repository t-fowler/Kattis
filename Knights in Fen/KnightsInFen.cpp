#include <algorithm>
#include <queue>
#include "KnightsInFen.hpp"

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

Node& Node::operator=(const Node &other) {
    this->parent = std::shared_ptr<Node>(
                    new Node(this->parent, this->position, this->appliedMove));
    this->position = other.getPosition();
    this->appliedMove = other.getAppliedMove();
    return *this;
}

int Node::getCost() const {
    if (parent == NULL) {
        return 0;
    }
    return parent->getCost() + 1;
}

Node Node::getParent() const {
    return *parent;
}

Board Node::getPosition() const {
    return position;
}

Move Node::getAppliedMove() const {
    return appliedMove;
}

std::vector<Move> KnightsInFen::moves(Board position) {
    std::vector<Move> result;
    int emptySquare;
    for (int i = 0; i < position.size(); i++) {
        if (position[i] == EMPTY)
            emptySquare = i;
    }

    // Up-up-left
    if ((emptySquare % 5) >= 1 && (emptySquare / 5) <= 2) {
        result.push_back(std::make_pair(emptySquare, emptySquare - 11));
    }
    // Up-left-left
    if((emptySquare % 5) >= 2 && (emptySquare / 5) <= 3) {
        result.push_back(std::make_pair(emptySquare, emptySquare - 7));
    }
    // Up-up-right
    if((emptySquare % 5) <= 3 && (emptySquare / 5) <= 2) {
        result.push_back(std::make_pair(emptySquare, emptySquare - 9));
    }
    // Up-right-right
    if((emptySquare % 5) <= 2 && (emptySquare / 5) <= 3) {
        result.push_back(std::make_pair(emptySquare, emptySquare - 3));
    }
    // Down-down-left
    if((emptySquare % 5) >= 1 && (emptySquare / 5) >= 2) {
        result.push_back(std::make_pair(emptySquare, emptySquare + 9));
    }
    // Down-left-left
    if((emptySquare % 5) >= 2 && (emptySquare / 5) >= 1) {
        result.push_back(std::make_pair(emptySquare, emptySquare + 3));
    }
    // Down-down-right
    if((emptySquare % 5) <= 3 && (emptySquare / 5) >= 2) {
        result.push_back(std::make_pair(emptySquare, emptySquare + 11));
    }
    // down-right-right
    if((emptySquare % 5) <= 2 && (emptySquare / 5) >= 1) {
        result.push_back(std::make_pair(emptySquare, emptySquare + 7));
    }

    return result;
}

Board KnightsInFen::makeMove(Board position, Move move) {
    Piece movePiece = position[move.second];
    position[move.first] = movePiece;
    position[move.second] = EMPTY;
    
    return position;
}

std::vector<Node> KnightsInFen::expand(std::shared_ptr<Node> node) {
    std::vector<Node> result;
    Board position = node->getPosition();
    for(Move move : moves(position)) {
        result.push_back(Node(node, makeMove(position, move), move));
    }
    return result;
}

KnightsInFen::KnightsInFen(Board initial) {
    this->initial = initial;
    this-> goal = {
        BLACK_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT,
        WHITE_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT, BLACK_KNIGHT,
        WHITE_KNIGHT, WHITE_KNIGHT, EMPTY, BLACK_KNIGHT, BLACK_KNIGHT,
        WHITE_KNIGHT, WHITE_KNIGHT, WHITE_KNIGHT, WHITE_KNIGHT, BLACK_KNIGHT,
        WHITE_KNIGHT, WHITE_KNIGHT, WHITE_KNIGHT, WHITE_KNIGHT, WHITE_KNIGHT,
    };
}

int KnightsInFen::solve() {
    Node node = Node(initial);
    if (node.getPosition() == goal) return 0;

    std::queue<Node> frontier;
    frontier.push(node);

    std::vector<Board> reached;
    reached.push_back(initial);

    while(!frontier.empty()) {
        node = frontier.front();
        frontier.pop();

        if (node.getCost() > 10) {
            return -1;
        }

        for (auto child : expand(std::shared_ptr<Node>(&node))) {
            if (child.getPosition() == goal) {
                return child.getCost();
            }
            if (std::find(reached.begin(), reached.end(), child.getPosition()) != reached.end()) {
                reached.push_back(child.getPosition());
                frontier.push(child);
            }
        }
    }

    return -1;
}