#include <vector>
#include <map>

#include "ForestGraph.hpp"

std::vector<Edge> readEdges(int E);
std::vector<Vertex> readFruitList(int C);
std::map<int, int> initTimer(int V, std::vector<Vertex> fruitClearings);
std::map<int, int> findShortestPaths(int V, std::vector<Edge> edgeList);