#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
    public:
    
       string findOrder(string dict[], int N, int K){
        vector<vector<int>> adj(K);
        for(int i=0;i<N-1;i++){
           string s1 = dict[i];
           string s2 = dict[i + 1];
           int len= min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                 break;
                }
            }
        }
       vector<int> topo= topoSort(K,adj);
       string ans= "";
       for(auto it:topo){
       ans=ans + char(it+'a');
   }
       return ans;

}
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