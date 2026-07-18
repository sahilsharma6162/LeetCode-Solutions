#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> surroundRegion(vector<vector<char>>& grid, int rows, int cols) {
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) &&
                    grid[i][j] == 'O') {
                    q.push({i, j});
                    grid[i][j] = 'S';
                }
            }
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;

            for (int i = 0; i < 4; i++) {
                int newRow = r + dr[i];
                int newCol = c + dc[i];

                if (newRow >= 0 && newRow < rows &&
                    newCol >= 0 && newCol < cols &&
                    grid[newRow][newCol] == 'O') {

                    grid[newRow][newCol] = 'S';
                    q.push({newRow, newCol});
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'O')
                    grid[i][j] = 'X';
                else if (grid[i][j] == 'S')
                    grid[i][j] = 'O';
            }
        }

        return grid;
    }
};