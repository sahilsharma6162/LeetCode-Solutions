#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Solution{
  public:
      bool dfs(int node,vector<vector<int>>& adjLs, vector<int>& color){
                color[node]=1;
                for(auto neighbour: adjLs[node]){
                    if(color[neighbour]==1)
                    return true;
                    if(color[neighbour]==0){
                        if(dfs(neighbour,adjLs,color)==true)
                        return true;
                    }
                }
                color[node]=2;
                return false;
      }

      bool isCycle(int V, vector<int> adj[]){
        vector<int> color(V, 0);
        vector<vector<int>> adjLs(V);
    //creating an adjacency list from vector adj:
        for (int i = 0; i < V; i++)
            for (int neighbor : adj[i])
                adjLs[i].push_back(neighbor);
     //for accessing each component:
        for (int i = 0; i < V; i++) {
            if (color[i]==0) {
                if (dfs(i, adjLs, color)==true)
                    return true;
            }
        }
        return false;
      }
};