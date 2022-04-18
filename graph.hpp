#include <map>
#include <vector>
#include <limits>

class Graph
{
private:
    int numberOfNodes_ = 0;
    std::map<int, std::vector<int>> connections_;

    int iterateThroughComponent(const int& node, std::map<int, bool>& visited);

public:
    Graph(int numberOfNodes);

    void addConnection(const int& node1, const int& node2);

    //calculates largest and smallest connected components
    //that are bigger then 1
    std::pair<int, int> calculateComponents();

    ~Graph();
};
