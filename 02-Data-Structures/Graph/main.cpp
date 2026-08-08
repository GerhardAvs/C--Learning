#include "Graph.h"
#include "utilities.h"

/**
 * @brief Main function of the program.
 * 
 * Creates a weighted graph and executes
 * Dijkstra's algorithm.
 * 
 * @return int Program execution status
 */
int main() {

    Graph<string> graph;

    graph.addEdge("A", "B", 7);
    graph.addEdge("A", "C", 3);
    graph.addEdge("B", "D", 4);
    graph.addEdge("C", "D", 2);
    graph.addEdge("C", "E", 8);
    graph.addEdge("D", "E", 1);
    graph.addEdge("D", "F", 5);
    graph.addEdge("E", "F", 2);
    
    graph.displayGraph();

    graph.dijkstra("A");

    return 0;
}