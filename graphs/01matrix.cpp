#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
     
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
       vector<vector<int>> distance;
              for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                      if(mat[i][j]==0){
                        distance[i][j]=0;
                      q.push({i,j});
                      }
                      else{
                      distance[i][j]=INT_MAX;
                      }
                }
            }

             int dr[] = {-1, 1, 0, 0};
           int dc[] = {0, 0, -1, 1};
           while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                 q.pop();

                for (int i = 0; i < 4; i++) {
                  int newRow = row + dr[i];
                  int newCol = col + dc[i];

                if (newRow >= 0 && newRow < mat.size() &&
                    newCol >= 0 && newCol < mat[0].size()) {

                    if (mat[newRow][newCol] == INT_MAX) {
                        distance[newRow][newCol] = distance[row][col]+1;;
                        q.push({newRow,newCol});

                    }
                }
            }
        }
        return distance;
    }
};