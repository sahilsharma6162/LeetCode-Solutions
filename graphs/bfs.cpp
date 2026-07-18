#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//bfs traversal:

class Solution{
    public:

vector<int> bfsTraversal(vector<bool>& visited, vector<vector<int>>& adj){
    
  queue<int> q;
  q.push(0);
  visited[0]=true;
  vector<int> bfs;

    while(!q.empty()){
      int node= q.front();
      q.pop();
      bfs.push_back(node);
      for(auto it: adj[node]){
        if(!visited[it]){
             visited[it]=true;
             q.push(it);
        }
      }
    }
  return bfs;
   }
};
