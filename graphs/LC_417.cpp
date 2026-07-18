#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& visited, vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto p = q.front();
            q.pop();

            int row = p.first;
            int col = p.second;

            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newRow < m &&
                    newCol >= 0 && newCol < n &&
                    !visited[newRow][newCol] &&
                    heights[newRow][newCol] >= heights[row][col]) {

                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        // Pacific: top row
        for (int j = 0; j < n; j++) {
            pacificQueue.push({0, j});
            pacific[0][j] = true;
        }

        // Pacific: left column
        for (int i = 1; i < m; i++) {
            pacificQueue.push({i, 0});
            pacific[i][0] = true;
        }

        // Atlantic: bottom row
        for (int j = 0; j < n; j++) {
            atlanticQueue.push({m - 1, j});
            atlantic[m - 1][j] = true;
        }

        // Atlantic: right column
        for (int i = 0; i < m - 1; i++) {
            atlanticQueue.push({i, n - 1});
            atlantic[i][n - 1] = true;
        }

        bfs(pacificQueue, pacific, heights);
        bfs(atlanticQueue, atlantic, heights);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};