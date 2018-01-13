#include "graph.h"

void Graph::addEdge(int src, int dest)
{
    adjacencies[src].push_back(dest);
    adjacencies[dest].push_back(src);
}

int Graph::getAdjListSize(int v) const
{
    return adjacencies[v].size();
}

void Graph::printGraph()
{
    for (int i = 0; i < V; i++)
    {
        std::cout << "Adjacency list of vertex " << i + 1 << " is:" << std::endl;
        for (auto p = adjacencies[i].begin(); p != adjacencies[i].end(); p++)
        {
            std::cout << *p << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::DFSUtils(int v, bool visited[])
{
    // mark as visited
    visited[v] = true;
    std::cout << v << std::endl;
    for (auto p = adjacencies[v].begin(); p != adjacencies[v].end(); p++)
    {
        if (!visited[*p]) DFSUtils(*p, visited);
    }
}

void Graph::depthFirstTraversal(int v)
{
    // keep track of visited vertices
    bool* visited = new bool[V];
    DFSUtils(v, visited);
}

void Graph::BFSUtils(int v, bool visited[])
{
    std::queue<int> q;
    visited[v] = true;
    q.push(v);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        std::cout << v << std::endl;
        for (auto p = adjacencies[v].begin(); p != adjacencies[v].end(); p++) {
            if (!visited[*p]) {
                q.push(*p);
                visited[*p] = true;
            }
        }
    }

}
void Graph::breadthFirstTraversal(int v)
{
    bool* visited = new bool[V];
    std::cout << "in bfs" << std::endl;
    BFSUtils(v, visited);
}