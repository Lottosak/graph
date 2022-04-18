#include "graph.hpp"

Graph::Graph(int numberOfNodes) : numberOfNodes_(numberOfNodes)
{
}

Graph::~Graph()
{
}

void Graph::addConnection(const int& node1, const int& node2)
{
    connections_[node1].emplace_back(node2);
    connections_[node2].emplace_back(node1);
}

std::pair<int, int> Graph::calculateComponents(){
    std::pair<int, int> sizes = {std::numeric_limits<int>::min(), std::numeric_limits<int>::max()};
    std::map<int, bool> visited;

    //prepare map to remember visited nodes
    for(auto node : connections_){
        visited[node.first] = false;
    }

    for(auto node : connections_){
        if(visited[node.first] == false){
            int size = iterateThroughComponent(node.first, visited);

            sizes.first = std::max(sizes.first, size);
            sizes.second = std::min(sizes.second, size);
        }
    }

    return sizes;
}

int Graph::iterateThroughComponent(const int& node, std::map<int, bool>& visited){

    int size = 1;

    visited[node] = true;

    for(auto connection : connections_[node]){
        if(visited[connection] == false){
            size += iterateThroughComponent(connection, visited);
        }
    }

    return size;
}