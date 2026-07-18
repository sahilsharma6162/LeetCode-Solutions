#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
    public:
        vector<int> topoSort(int V, vector<vector<pair<int,int>>>& adj){
           vector<int> inDegree (V,0);
           vector<int> result;

           queue<int> q;
           for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                int neighbor = adj[i][j].first;
                 inDegree[neighbor]++;
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
         for(auto it: adj[node]){
            int neighbor=it.first;
        inDegree[neighbor]--;
        if(inDegree[neighbor]==0){
             q.push(neighbor);
           }
        }
     }
        return result;
        
    }

         vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){
         int V = 3;
         vector<vector<pair<int, int>>> adj(N);
         vector<int> distance(N, INT_MAX);
         distance[0] = 0;

         for (int i = 0; i < M; i++) {
         int u = edges[i][0];
         int v = edges[i][1];
         int wt = edges[i][2];

            adj[u].push_back({v, wt});
           }
         vector<int> topo= topoSort(N,adj);
              for(auto node: topo)
             for(auto it: adj[node]){
                int neighbour= it.first;
                int weight=it.second;
             if(distance[node]!=INT_MAX){
                if (distance[node] + weight < distance[neighbour]){
                  distance[neighbour] = distance[node] + weight;
                }
            }
    }
              for(int i=0;i<distance.size();i++){
                if(distance[i]==INT_MAX)
                distance[i]=-1;
              }
              return distance;
        }
      
};