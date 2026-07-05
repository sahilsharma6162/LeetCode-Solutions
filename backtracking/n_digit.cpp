#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    void backtrack(vector<int>& ans,int N,int start, string current){
        if(N==current.length()){
            ans.push_back(stoi(current));
            return;
        }
        for(int i=start;i<=9;i++){
            current.push_back(i+'0');
            backtrack(ans, N, i+1, current);
            current.pop_back();

        }
    }
};