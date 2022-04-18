#include <iostream>
#include "graph.hpp"

int main(void){

    int numberOfNodes = 0;
    std::cout << "Put number of nodes in graph." << std::endl; 
    std::cin >> numberOfNodes;

    Graph graph(numberOfNodes);

    int numberOfConnections = 0;
    std::cout << "Put number of connections in graph." << std::endl;
    std::cin >> numberOfConnections;

    for(int i = 0; i < numberOfConnections; i++){
        std::cout << "Connection (format: node1 node2) " << i << "/" << numberOfConnections << std::endl;
        int node1, node2;
        std::cin >> node1 >> node2;
        graph.addConnection(node1, node2);
    }

    auto sizes = graph.calculateComponents();

    std::cout << "Largest component: " << sizes.first << " smallest component: " << sizes.second << std::endl;
    return 0;
}