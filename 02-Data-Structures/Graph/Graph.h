#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>

using namespace std;

/**
 * @brief Generic weighted graph implementation using adjacency list.
 * 
 * @tparam T Node data type
 */
template <typename T>
class Graph {
private:
    
    /**
     * @brief Adjacency list representation.
     * Key = node
     * Value = list of neighbors and weights
     */
    map<T, vector<pair<T, int>>> adjacencyList;

public:

    /**
     * @brief Adds an edge between two nodes.
     * 
     * @param source Starting node
     * @param destination Ending node
     * @param weight Edge weight
     */
    void addEdge(T source, T destination, int weight);

    /**
     * @brief Displays graph adjacency list.
     */
    void displayGraph();

    /**
     * @brief Executes Dijkstra's shortest path algorithm.
     * 
     * @param source Starting node
     */
    void dijkstra(T source);
};


/**
 * @brief Adds a weighted edge to the graph.
 */
template <typename T>
void Graph<T>::addEdge(T source, T destination, int weight) {
    adjacencyList[source].push_back({destination, weight});
    adjacencyList[destination].push_back({source, weight});
}


/**
 * @brief Prints adjacency list representation.
 */
template <typename T>
void Graph<T>::displayGraph() {
    cout << "\nAdjacency List:\n";

    for (auto node : adjacencyList) {
        cout << node.first << " -> ";

        for (auto neighbor : node.second) {
            cout << "(" << neighbor.first 
                 << ", weight: " 
                 << neighbor.second << ") ";
        }

        cout << endl;
    }
}


/**
 * @brief Finds shortest paths using Dijkstra algorithm.
 */
template <typename T>
void Graph<T>::dijkstra(T source) {

    priority_queue<
        pair<int, T>,
        vector<pair<int, T>>,
        greater<pair<int, T>>
    > priorityQueue;

    map<T, int> distances;

    for (auto node : adjacencyList) {
        distances[node.first] = numeric_limits<int>::max();
    }

    distances[source] = 0;
    priorityQueue.push({0, source});

    while (!priorityQueue.empty()) {

        T currentNode = priorityQueue.top().second;
        int currentDistance = priorityQueue.top().first;

        priorityQueue.pop();

        for (auto neighbor : adjacencyList[currentNode]) {

            T adjacentNode = neighbor.first;
            int weight = neighbor.second;

            if (currentDistance + weight < distances[adjacentNode]) {
                distances[adjacentNode] = currentDistance + weight;

                priorityQueue.push({
                    distances[adjacentNode],
                    adjacentNode
                });
            }
        }
    }

    cout << "\nShortest distances from node "
         << source << ":\n";

    for (auto node : distances) {
        cout << node.first << " -> ";

        if (node.second == numeric_limits<int>::max()) {
            cout << "Unreachable";
        }
        else {
            cout << node.second;
        }

        cout << endl;
    }
}

#endif