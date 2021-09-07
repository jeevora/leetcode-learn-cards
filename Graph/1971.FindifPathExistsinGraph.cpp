#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;


// Data structure to store a graph edge
struct Edge {
    int src, dest;
};

// A class to represent a graph object
class Graph {
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type `vector<int>`
        adjList.resize(N);
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
    }
};

int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {0, 1}, {1, 2}, {2, 0}
        // vertex 0, 13, and 14 are single nodes
    };
 
    // total number of nodes in the graph
    // number of node + zero index in c++
    int N = 3;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N, false);
    
    //Solution sl;
    // Perform BFS traversal from all undiscovered nodes to
    // cover all unconnected components of a graph
    for (int i = 0; i < N; i++)
    {
        //bucket
        int vu = 0;
        if (discovered[i] == false)
        {
            // start BFS traversal from vertex `i`
            if(BFS(graph, i, discovered, N, vu))
                break;
        }
    } 
    
    return 0;
}