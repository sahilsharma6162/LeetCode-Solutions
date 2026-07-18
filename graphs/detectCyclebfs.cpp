#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
    public:

         bool bfs(int node, int parentNode, vector<int>& visited, vector<vector<int>>& adj ){
                queue<pair<int,int>> q;
                    q.push({node, parentNode});
                    visited[node]=1;
                      while(!q.empty()){
                        auto [node, parentNode] = q.front();  
                        q.pop();
                     for(auto it: adj[node]){
                     if(!visited[it]){
                      visited[it]=true;
                       q.push({it,node});

                      }
                      else if(visited[it]==1 && it!=parentNode){
                        return true;
                      }
                 }
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
                if (bfs(i, -1, visited, adjLs))
                    return true;
            }
        }
        return false;
    }
};