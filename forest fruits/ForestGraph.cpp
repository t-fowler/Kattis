#include "ForestGraph.hpp"

//
// class Vertex
//

Vertex::Vertex(int i)
{
    this->i = i;
    this->d = -1;
}

int Vertex::index() {
    return i;
}

int Vertex::distance() {
    return d;
}

//
// class Edge
//

Edge::Edge(int u, int v, int w)
{
    this->u = u;
    this->v = v;
    this->w = w;
}

int Edge::fromNode() {
    return u;
}

int Edge::toNode() {
    return v;
}

int Edge::weight() {
    return w;
}