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

    std::vector<std::shared_ptr<Vertex>> vertexList;
    for (int i = 1; i <= V; ++i) {
        vertexList.push_back(std::shared_ptr<Vertex>(new Vertex(i)));
    }
    std::vector<Edge> edgeList = readEdges(E, vertexList);
    std::vector<std::shared_ptr<Vertex>> fruitClearings = readFruitList(C, vertexList);
    findShortestPaths(V, vertexList, edgeList);
    
    auto compareDistance = [](const std::shared_ptr<Vertex> &a, const std::shared_ptr<Vertex> &b) {
        if (a->distance() == b->distance()) return false;
        if (a->distance() == INT_MAX) return false;
        if (b->distance() == INT_MAX) return true;
        return a->distance() - b->distance() < 0;
    };
    std::sort(fruitClearings.begin(), fruitClearings.end(), compareDistance);

    /*
    std::cerr << "Fruit clearings ordered by distance: ";
    for (auto clearing : fruitClearings) {
        std::cerr << clearing->index() << " ";
    }
    std::cerr << std::endl;

    for (int i = 1; i <= V; ++i) {
        std::cerr << "Distance to " << i << " is " 
            << vertexList[i-1]->distance() << "." << std::endl;
    }
    */

    if (fruitClearings.size() < days || 
        fruitClearings[days-1]->distance() == INT_MAX) {
        std::cout << -1 << std::endl;
    } else {
        //std::cerr << "Kth shortest distance: " << fruitClearings[days-1]->index() << std::endl;
        std::cout << fruitClearings[days-1]->distance() * 2 << std::endl;
    }

    return 0;
}

/**
 * @brief Reads all the edges provided by standard input.
 * 
 * @param E The number of Edges (lines) to read.
 * @return std::vector<Edge> The edge list.
 */
std::vector<Edge> readEdges(int E, const std::vector<std::shared_ptr<Vertex>> &vertexList) {
    std::vector<Edge> edgeList;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edgeList.push_back(Edge(vertexList[u-1], vertexList[v-1], w));
        edgeList.push_back(Edge(vertexList[v-1], vertexList[u-1], w));
    }
    return edgeList;
}

/**
 * @brief Reads all the indices for clearings that grow fruit from standard input.
 * 
 * @param C The number of clearings that grow fruit.
 * @return std::vector<std::shared_ptr<Vertex>> The list of clearings.
 */
std::vector<std::shared_ptr<Vertex>> readFruitList(int C, const std::vector<std::shared_ptr<Vertex>> &vertexList) {
    std::vector<std::shared_ptr<Vertex>> fruitClearings;
    for (int i = 0; i < C; ++i) {
        int v;
        std::cin >> v;
        fruitClearings.push_back(vertexList[v-1]);
    }
    return fruitClearings;
}

/**
 * @brief Calculates the distance of the shortest path from the cottage clearing (1)
 * to each other clearing. 
 * 
 * @param edgeList The list of edges in the graph.
 */
void findShortestPaths(
        int V, 
        const std::vector<std::shared_ptr<Vertex>> &vertexList, 
        const std::vector<Edge> &edgeList) {

    auto compareDistance = [](const std::shared_ptr<Vertex> &a, const std::shared_ptr<Vertex> &b) {
        if (a->distance() == b->distance()) return false;
        if (a->distance() == INT_MAX) return false;
        if (b->distance() == INT_MAX) return true;
        return a->distance() - b->distance() < 0;
    };
    std::vector<std::shared_ptr<Vertex>> queue;
    vertexList[0]->setDistance(0);
    queue.push_back(vertexList[0]);

    while (!queue.empty()) {
        std::shared_ptr<Vertex> node = queue.front();
        std::pop_heap(queue.begin(), queue.end(), compareDistance);
        queue.pop_back();
        
        for (Edge e : edgeList) {
            if (e.fromNode() != node) continue;

            auto nextNode = e.toNode();
            if (nextNode->distance() > node->distance() + e.weight()) {
                nextNode->setDistance(node->distance() + e.weight());
                if (std::find(queue.begin(), queue.end(), nextNode) != queue.end()) {
                    std::remove(queue.begin(), queue.end(), nextNode);
                    std::make_heap(queue.begin(), queue.end());
                }
                queue.push_back(nextNode);
                std::push_heap(queue.begin(), queue.end(), compareDistance);
            }
        }
    }
}