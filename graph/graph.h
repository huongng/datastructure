/** ADT GRAPH OPERATIONS
 * Test if graph is empty
 * Get number of vertices
 * Get number of edges
 * See if an edge exists between two vertices
 * Add a new vertex
 * Add a new edge between two vertices
 * Delete a vertex and any of its edges
 * Delete an edge between two vertices
 * Find a vertex with a given value
***/
#ifndef GRAPH_INTF
#define GRAPH_INTF

#include <vector>
#include <iostream>
#include <stack>
#include <queue>

struct Node
{
    int dest;
    Node* next;
    Node(int dest) : dest(dest), next(nullptr) {}
};

class Graph
{
private:
    int V; // number of vertices;
    std::vector< std::vector<int> >adjacencies;
    void DFSUtils(int v, bool visited[]);
    void BFSUtils(int v, bool visited[]);
public:
    Graph(int V) : V(V) {
        adjacencies = std::vector<std::vector<int> >(V);
    }
    void addEdge(int src, int dest);
    void printGraph();
    int getAdjListSize(int v) const;
    void depthFirstTraversal(int v);
    void breadthFirstTraversal(int v);
};
#endif