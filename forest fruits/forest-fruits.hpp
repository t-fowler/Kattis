#include <vector>
#include <unordered_map>

#include "ForestGraph.hpp"

std::vector<Edge> readEdges(int E, const std::vector<std::shared_ptr<Vertex>> &vertexList);
std::vector<std::shared_ptr<Vertex>> readFruitList(int C, const std::vector<std::shared_ptr<Vertex>> &vertexList);
void findShortestPaths(
    int V,
    const std::vector<std::shared_ptr<Vertex>> &vertexList,
    const std::vector<Edge> &edgeList);