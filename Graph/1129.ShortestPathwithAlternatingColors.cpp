#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {

    void bfs(vector<pair<int, char>> graph[], int start, int end, int n, vector<int>& ans){

        queue<pair<int,int>> queue;

        vector<int> distance(n,0);
        distance[start] = 1;

        queue.push({1,start});

        while(!queue.empty()){

            int u = queue.front().second;
            queue.pop();



        }

    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {

        // pair with vector
        // vector<vector<pair<int,char>>> graph[n];

        // for(auto edge: red_edges){
        //     int u = edge[0], v = edge[1];
        //     graph[u].push_back({{v,'r'}});
        // }

        // for(auto edge: blue_edges){
        //     int u = edge[0], v = edge[1];
        //     graph[u].push_back({{v,'b'}});
        // }

        // pair without vector
        vector<pair<int,char>> graph[n];

        for(auto edge: red_edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back({v,'r'});
        }

        for(auto edge: blue_edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back({v,'b'});
        }

        int w = 0;
        // vector<vector<char>> graph(n,vector<char>(n,'n'));

        // for(auto edge: red_edges){
        //     int u = edge[0], v = edge[1];
        //     graph[u][v] = 'r';
        // }

        // for(auto edge: blue_edges){
        //     int u = edge[0], v = edge[1];
        //     graph[u][v] = 'b';
        // }

        vector<int> ans(n,-1);

        for(int v = 1; v < n; ++v)
            bfs(graph, 0, v, n, ans);

        return ans;
    }
};

int main(){

    int n = 3;
    vector<vector<int>> red_edges = {
        {0,1},{1,2}
    };

    vector<vector<int>> blue_edges = {
    };

    Solution sl;
    sl.shortestAlternatingPaths(n, red_edges, blue_edges);
}