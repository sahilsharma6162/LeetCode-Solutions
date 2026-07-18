#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {

        vector<vector<int>> adj(N);

        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(N, INT_MAX);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neighbour : adj[node]) {
                if (dist[node] + 1 < dist[neighbour]) {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};