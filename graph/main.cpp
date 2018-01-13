#include "graph.h"

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    //g.printGraph();

    g.depthFirstTraversal(0);
    std::cout << "----" << std::endl;
    g.breadthFirstTraversal(0);
    return 0;
}