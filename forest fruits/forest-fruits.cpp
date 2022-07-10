#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include "forest-fruits.hpp"


int main() {
    int V, E, C, K, M;
    std::cin >> V >> E >> C >> K >> M >> std::ws;

    std::vector<Edge> edgeList = readEdges(E);
    std::vector<Vertex> fruitClearings = readFruitList(C);
    std::map<int, int> fruitTimer = initTimer(V, fruitClearings);
    std::map<int, int> distanceToFruit = findShortestPaths(V, edgeList);

    for (int i = 1; i <= V; ++i) {
        std::cerr << "Distance to " << i << " is " 
            << distanceToFruit[i] << "." << std::endl;
    }
    /*
    for (int i = 0; i < M; ++i) {

    }
    */
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
 * @return std::vector<Vertex> The list of clearings.
 */
std::vector<Vertex> readFruitList(int C) {
    std::vector<Vertex> fruitClearings;
    for (int i = 0; i < C; ++i) {
        int v;
        std::cin >> v;
        fruitClearings.push_back(v);
    }
    return fruitClearings;
}

/**
 * @brief Provides a timer for tracking fruit growth in each clearing.
 * 
 * @param V The number of clearings.
 * @param fruitClearings A vector containing all the clearings that grow fruit.
 * 
 * @return std::map<int, int> A map from clearing index to an integer representing
 * the number of days until fruit grows in the clearing. If the value is negative,
 * then the clearing does not grow fruit. If it is zero, then the clearing contains
 * fruit. If positive, then the clearing will grow fruit in that number of days.
 * *Positive values must be decremented each day*.
 */
std::map<int, int> initTimer(int V, std::vector<Vertex> fruitClearings) {
    std::map<int, int> fruitTimer;
    for (int i = 1; i <= V; ++i) {
        fruitTimer[i] = -1;
    }
    for (Vertex v : fruitClearings) {
        fruitTimer[v.index()] = 0;
    }
    return fruitTimer;
}

/**
 * @brief Calculates the distance of the shortest path from the cottage clearing (1)
 * to each other clearing. 
 * 
 * @param edgeList The list of edges in the graph.
 * @return std::map<int, int> a map from clearing indices to the distance from the
 * cottage clearing.
 */
std::map<int, int> findShortestPaths(int V, std::vector<Edge> edgeList) {
    std::vector<int> visited = {1};
    std::map<int, int> distanceTo;
    for (int i = 1; i <= V; ++i) {
        distanceTo[i] = INT_MAX;
    }
    distanceTo[1] = 0;

    auto compareDistance = [&](int a, int b) {
        if (distanceTo[a] == distanceTo[b]) return 0;
        if (distanceTo[a] == -1) return 1;
        if (distanceTo[b] == -1) return -1;
        return distanceTo[a] - distanceTo[b];
    };
    std::vector<int> queue;
    queue.push_back(1);
    std::push_heap(queue.begin(), queue.end(), compareDistance);

    while (!queue.empty()) {
        std::pop_heap(queue.begin(), queue.end(), compareDistance);
        int node = queue.back();
        queue.pop_back();
        

        for (Edge e : edgeList) {
            if (e.fromNode() != node) continue;

            int nextNode = e.toNode();
            if (distanceTo[nextNode] > distanceTo[node] + e.weight()) {
                distanceTo[nextNode] = distanceTo[node] + e.weight();
                if (std::find(queue.begin(), queue.end(), nextNode)
                    == queue.end()) {
                    queue.push_back(nextNode);
                    std::push_heap(queue.begin(), queue.end(), compareDistance);
                } else {
                    std::remove(queue.begin(), queue.end(), nextNode);
                    std::make_heap(queue.begin(), queue.end(), compareDistance);
                    queue.push_back(nextNode);
                    std::push_heap(queue.begin(), queue.end(), compareDistance);
                }
            }
        }
    }

    return distanceTo;
}