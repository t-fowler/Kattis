#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include "forest-fruits.hpp"


int main() {
    int V, E, C, K, M;
    std::cin >> V >> E >> C >> K >> M >> std::ws;

    int days = M;
    if (K < M) {
        days = K;
    }

    std::vector<Edge> edgeList = readEdges(E);
    std::vector<int> fruitClearings = readFruitList(C);
    std::map<int, int> distanceToFruit = findShortestPaths(V, edgeList);
    
    auto compareDistance = [&](int a, int b) {
        if (distanceToFruit[a] == distanceToFruit[b]) return false;
        if (distanceToFruit[a] == INT_MAX) return false;
        if (distanceToFruit[b] == INT_MAX) return true;
        return distanceToFruit[b] - distanceToFruit[a] > 0;
    };
    std::sort(fruitClearings.begin(), fruitClearings.end(), compareDistance);

/*
    std::cerr << "Fruit clearings ordered by distance: ";
    for (auto i : fruitClearings) {
        std::cerr << i << " ";
    }
    std::cerr << std::endl;

    for (int i = 1; i <= V; ++i) {
        std::cerr << "Distance to " << i << " is " 
            << distanceToFruit[i] << "." << std::endl;
    }
*/



    if (fruitClearings.size() < days || fruitClearings[days-1] == INT_MAX) {
        std::cout << -1 << std::endl;
    } else {
        //std::cerr << "Kth shortest distance: " << fruitClearings[days-1] << std::endl;
        std::cout << distanceToFruit[fruitClearings[days-1]]*2 << std::endl;
    }

    return 0;
}

/**
 * @brief Reads all the edges provided by standard input.
 * 
 * @param E The number of Edges (lines) to read.
 * @return std::vector<Edge> The edge list.
 */
std::vector<Edge> readEdges(int E) {
    std::vector<Edge> edgeList;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
        edgeList.push_back(Edge(v, u, w));
    }
    return edgeList;
}

/**
 * @brief Reads all the indices for clearings that grow fruit from standard input.
 * 
 * @param C The number of clearings that grow fruit.
 * @return std::vector<int> The list of clearings.
 */
std::vector<int> readFruitList(int C) {
    std::vector<int> fruitClearings;
    for (int i = 0; i < C; ++i) {
        int v;
        std::cin >> v;
        fruitClearings.push_back(v);
    }
    return fruitClearings;
}

/**
 * @brief Calculates the distance of the shortest path from the cottage clearing (1)
 * to each other clearing. 
 * 
 * @param edgeList The list of edges in the graph.
 * @return std::map<int, int> a map from clearing indices to the distance from the
 * cottage clearing.
 */
std::map<int, int> findShortestPaths(int V, std::vector<Edge> &edgeList) {
    std::vector<int> visited = {1};
    std::map<int, int> distanceTo;
    for (int i = 1; i <= V; ++i) {
        distanceTo[i] = INT_MAX;
    }
    distanceTo[1] = 0;

    auto compareDistance = [&](int a, int b) {
        if (distanceTo[a] == distanceTo[b]) return 0;
        if (distanceTo[a] == INT_MAX) return 1;
        if (distanceTo[b] == INT_MAX) return -1;
        return distanceTo[a] - distanceTo[b];
    };
    std::priority_queue<int, std::vector<int>, decltype(compareDistance)> queue(compareDistance);
    queue.push(1);

    while (!queue.empty()) {
        int node = queue.top();
        queue.pop();
        

        for (Edge e : edgeList) {
            if (e.fromNode() != node) continue;

            int nextNode = e.toNode();
            if (distanceTo[nextNode] > distanceTo[node] + e.weight()) {
                distanceTo[nextNode] = distanceTo[node] + e.weight();
                queue.push(nextNode);
            }
        }
    }

    return distanceTo;
}