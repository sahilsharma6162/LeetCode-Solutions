#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        // If the new color is the same as the original color,
        // no need to perform BFS.
        if (image[sr][sc] == color)
            return image;

        int originalColor = image[sr][sc];

        queue<pair<int, int>> q;

        // q.push(sr,sc); ❌
        // push() takes one argument, so push a pair.
        q.push({sr, sc});

        // Mark the starting cell as visited by changing its color.
        image[sr][sc] = color;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            // Take the current cell from the queue.
            pair<int, int> p = q.front();
            q.pop();

            // Update row and col for every cell.
            int row = p.first;
            int col = p.second;

            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                // image.size() = number of rows
                // image[0].size() = number of columns
                if (newRow >= 0 && newRow < image.size() &&
                    newCol >= 0 && newCol < image[0].size()) {

                    // Process only pixels having the original color.
                    if (image[newRow][newCol] == originalColor) {

                        // Change color immediately so it isn't added again.
                        image[newRow][newCol] = color;

                        // q.push(newRow,newCol); ❌
                        // Push a pair.
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        return image;
    }
};