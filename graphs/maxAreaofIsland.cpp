#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int startRow;
        int startCol;

        for(int i=0; i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                 if(grid[i][j]==1){
                      int compSize=0;
                     startCol=j;
                     startRow=i;
       grid[startRow][startCol]=0;
            queue<pair<int,int> >q;
            q.push({startRow,startCol});

           int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

                while (!q.empty()) {
                    pair<int,int> p=q.front();
                    q.pop();

                    compSize++;
                    int row = p.first;
                    int col = p.second;

                    for (int i = 0; i < 4; i++) {
                  int newRow = row + dr[i];
                  int newCol = col + dc[i];

                if (newRow >= 0 && newRow < grid.size() &&
                    newCol >= 0 && newCol < grid[0].size()) {

                    if (grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 0;
                        q.push({newRow,newCol});
                    }
                 }
              }

           }
                    maxArea=max(maxArea,compSize);

        }
    }

}
return maxArea;        
    }
};