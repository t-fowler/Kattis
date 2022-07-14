#include <climits>
#include "ForestGraph.hpp"

//
// class Vertex
//

Vertex::Vertex(int i)
{
    this->i = i;
    this->d = INT_MAX;
}

int Vertex::index() {
    return i;
}

int Vertex::distance() {
    return d;
}

void Vertex::setDistance(int d) {
    this->d = d;
}

//
// class Edge
//

Edge::Edge(std::shared_ptr<Vertex> u, std::shared_ptr<Vertex> v, int w)
{
    this->u = u;
    this->v = v;
    this->w = w;
}

std::shared_ptr<Vertex> Edge::fromNode() {
    return u;
}

std::shared_ptr<Vertex> Edge::toNode() {
    return v;
}

int Edge::weight() {
    return w;
}

//
// class ForestGraph
//
/*
class ForestGraph {
  private:
    int V;
    int E;
    std::vector<std::vector<int>> adj;
  public:
    ForestGraph(int V);
    void addEdge(int v, int w);
    std::vector<int> adj(int v);
}
*/

ForestGraph::ForestGraph(int V, int E) {
    this->V = V;
    this->E = E;
    this->adj.push_back(std::vector<Edge>());
}

void ForestGraph::addEdge(Edge &e) {
    this->adj[e.fromNode()->index()].push_back(e);
    this->adj[e.toNode()->index()].push_back(Edge(e.toNode(), e.fromNode(), e.weight()));
}

std::vector<Edge> adjacentTo()