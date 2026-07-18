#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> adjLs[isConnected.size()];
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(isConnected.size(),false);
        int Num=0;
       for(int i=0;i<visited.size();i++){
        if(!visited[i]){
            Num++;
             dfs(i,adjLs,visited);
        }
       }
       return Num;
    }
    void dfs(int node, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

};