#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Step 1: Calculate in-degree of all nodes
// Step 2: Push all nodes with in-degree 0 into queue
// Step 3: Pop a node → add to result → reduce in-degree of all its neighbors
// Step 4: If any neighbor's in-degree becomes 0 → push to queue
// Step 5: Repeat until queue empty

class Solution {
public:
     vector<int> topoSort(int V, vector<vector<int>>& adj){
           vector<int> inDegree (V,0);
           vector<int> result;

           queue<int> q;
           for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                 inDegree[adj[i][j]]++;
            }
           }
           for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
           }

           while(!q.empty()){
             int node=q.front();
             q.pop();
           result.push_back(node);
      for(auto neighbor: adj[node]){
        inDegree[neighbor]--;
        if(inDegree[neighbor]==0){
             q.push(neighbor);
           }
         }
        }
        return result;
        
      } 
};

