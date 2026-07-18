#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//dfs traversal:

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        visited[node] = true;
        ans.push_back(node);

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> ans;
        vector<bool> visited(V, false);

        dfs(0, adj, visited, ans);

        return ans;
    }
};