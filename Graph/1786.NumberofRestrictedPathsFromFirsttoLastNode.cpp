#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

class Solution {
    // using topological sort


    // using dijkstra shortest path with adjLis + minHeap
    void dijkstra(vector<pair<int, int>> graph[], int n, int src, int dst, vector<int>& ans){

        priority_queue< pair<int,int>, vector<pair<int,int>> , greater<> > p_queue;

        vector<int> distance(n, INT_MAX);

        p_queue.push({0,src});

        while (!p_queue.empty())
        {
            int u = p_queue.top().second;
            int dis = p_queue.top().first;
            p_queue.pop();

            if(u == dst)
                break;

            for(auto it: graph[u]){
                
                int v = it.first;
                int w = it.second;

                if(distance[v] > dis + w)
                    distance[v] = dis + w,
                        p_queue.push({distance[v], v});
            }
        }

        ans[src] = distance[dst];
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> graph[n];
        vector<int> shortestPath(n, 0);

        for(auto edge: edges)
            graph[edge[0]].push_back({edge[1],edge[2]}),
                graph[edge[1]].push_back({edge[0],edge[2]});

        // 1st step to calculate shortestpath from node 1 to last node
        for(int u = 1; u < n-1; ++u)
            dijkstra(graph, n, u, n-1, shortestPath);

        // remove unecessary edges to transform the graph as DAG
        for(auto edge: edges){
            if(shortestPath[edge[0]] )
                graph[].;
        }


        // topologicalsort over DAG
        int w = 1;

        return 1;
    }
};

int main(){

    vector<vector<int>> edges = {
        {1,2,3},
        {1,3,3},
        {2,3,1},
        {1,4,2},
        {5,2,2},
        {3,5,1},
        {5,4,10}
    };
    int n = 5;

    Solution sl;
    cout << sl.countRestrictedPaths(n+1, edges);
}