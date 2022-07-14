#include <memory>
#include <vector>

class Vertex {
  private:
    int i;
    int d;
  public:
    Vertex(int i);
    int index();
    int distance();
    void setDistance(int d);
};

class Edge {
  private:
    std::shared_ptr<Vertex> u;
    std::shared_ptr<Vertex> v;
    int w;
  public:
    Edge(std::shared_ptr<Vertex> u, std::shared_ptr<Vertex> v, int w);
    std::shared_ptr<Vertex> fromNode();
    std::shared_ptr<Vertex> toNode();
    int weight();
};

class ForestGraph {
  private:
    int V;
    int E;
    std::vector<std::vector<Edge>> adj;
  public:
    ForestGraph(int V, int E);
    void addEdge(Edge &e);
    std::vector<Edge> adjacentTo(int v);
};