class Vertex {
  private:
    int i;
    int d;
  public:
    Vertex(int i);
    int index();
    int distance();
};

class Edge {
  private:
    int u;
    int v;
    int w;
  public:
    Edge(int u, int v, int w);
    int fromNode();
    int toNode();
    int weight();
};