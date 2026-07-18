#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
    public:

    void bfs(vector<vector<int>>& bombs){

    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<int> adjLs[bombs.size()];
        for(int i=0;i<bombs.size();i++){
            for(int j=0;j<bombs[0].size();j++){
                if(bombs[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
    }
};