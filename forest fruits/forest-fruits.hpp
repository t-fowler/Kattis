#include <vector>
#include <map>

#include "ForestGraph.hpp"

std::vector<Edge> readEdges(int E);
std::vector<int> readFruitList(int C);
std::map<int, int> findShortestPaths(int V, std::vector<Edge> &edgeList);