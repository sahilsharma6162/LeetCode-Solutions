#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int targetSum;
    
    void backtrack(int start, int currentSum, vector<int>& result, vector<int>& nums, vector<vector<int>>& ans){
        if(currentSum == targetSum){
          ans.push_back(result);
          return;
        }
        if(currentSum > targetSum){
            return;
        }
        for(int i = start; i < nums.size(); i++){
            result.push_back(nums[i]);
            backtrack(i, currentSum + nums[i], result, nums, ans);
            result.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        targetSum = target;
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(0, 0, temp, candidates, ans);
        return ans;
    }
};

int main(){
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution s;
    vector<vector<int>> result = s.combinationSum(candidates, target);

    for(auto& row : result){
        for(int x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}