#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
     int orangesRotting(vector<vector<int>>& grid) {
             int minutes=-1;
             
             queue<pair<pair<int,int>,int>> q;
              for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                      if(grid[i][j]==2){
                      q.push({{i,j},0});

                      }
                }
            }
           int dr[] = {-1, 1, 0, 0};
           int dc[] = {0, 0, -1, 1};
           int count=0;

            while(!q.empty()){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int tm= q.front().second;
                 q.pop();

               minutes=max(minutes,tm);
                    for (int i = 0; i < 4; i++) {
                  int newRow = row + dr[i];
                  int newCol = col + dc[i];

                if (newRow >= 0 && newRow < grid.size() &&
                    newCol >= 0 && newCol < grid[0].size()) {

                    if (grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({{newRow,newCol},tm+1});

                  }
              }
            }
         }
         for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                      if(grid[i][j]==1){
                       return -1;
                      }
            }  
    }
           return minutes;
    }
};

