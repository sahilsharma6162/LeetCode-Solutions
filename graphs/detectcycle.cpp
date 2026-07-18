#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
    public:
      
      bool dfs(int node, int parentNode, vector<vector<int>>& adjLs, vector<int>& visited){
        visited[node] = 1;

        for (auto neighbor : adjLs[node]) {
            if (!visited[neighbor]) {
                if(dfs(neighbor,node, adjLs, visited)==true)
                    return true;  
            }
            else if(neighbor!=parentNode)
                return true;
        }
        return false;
      }
      
      bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<vector<int>> adjLs(V);
    //creating an adjacency list from vector adj:
        for (int i = 0; i < V; i++)
            for (int neighbor : adj[i])
                adjLs[i].push_back(neighbor);
     //for accessing each component:
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adjLs, visited))
                    return true;
            }
        }
        return false;
    }
};