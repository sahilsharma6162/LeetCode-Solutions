#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
      vector<int> topoSort(int V, vector<vector<int>>& adj){
           vector<int> outDegree (V,0);
           vector<int> result;
          vector<vector<int>> adjLs(V);
           queue<int> q;

           // reversing orginal graph:
            for (int i = 0; i < V; i++)
            for (int neighbor : adj[i])
                adjLs[neighbor].push_back(i);

         //building outdegree vector:
           for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                 outDegree[i]++;
            }
        }
           for(int i=0;i<V;i++){
            if(outDegree[i]==0){
                q.push(i);
            }
        }

           while(!q.empty()){
            int node=q.front();
             q.pop();
           result.push_back(node);
      for(auto neighbor: adjLs[node]){
        outDegree[neighbor]--;
        if(outDegree[neighbor]==0){
             q.push(neighbor);
           }
         }
        }
        sort(result.begin(), result.end());
        return result;
        
      } 
};
