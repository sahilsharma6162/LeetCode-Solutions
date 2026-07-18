#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:

    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int,int>> q;
        int count;
        q.push({r, c});
        grid[r][c] = 'V';
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;

            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newRow < grid.size() &&
                    newCol >= 0 && newCol < grid[0].size() &&
                    grid[newRow][newCol] == '1') {
                    grid[newRow][newCol] = 'V';
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int numEnclaves(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
       int count;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i == 0 || i == rows-1 || j == 0 || j == cols-1) && grid[i][j] == '1') {
                    bfs(grid, i, j);
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') 
                count++;
            }
        }
        return count;
    }
};

// int main() {
//     vector<vector<char>> board = {
//         {'X','X','X','X'},
//         {'X','O','O','X'},
//         {'X','X','O','X'},
//         {'X','O','X','X'}
//     };

//     Solution sol;
//     sol.solve(board);

//     for (auto& row : board) {
//         for (char c : row) cout << c << " ";
//         cout << endl;
//     }
//     return 0;
// }