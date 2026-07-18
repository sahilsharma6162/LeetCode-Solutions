#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
      bool dfs(int node,vector<vector<int>>& graph,vector<int>& color){
         color[node]=1;
         vector<int> result;
         for(auto neighbour: graph[node]){
                    if(color[neighbour]==1)
                    return true;
                    if(color[neighbour]==0){
                        if(dfs(neighbour,graph,color)==true)
                        return true;
                    }
                }
                color[node]=2;
                result.push_back(node);
                return false;
      }
      
       vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>result;
        vector<int> color(n,0);
         for (int i = 0; i < n; i++)
        dfs(i, graph, color);

    for (int i = 0; i < n; i++)
        if (color[i] == 2)
            result.push_back(i);

    return result;
    }
};