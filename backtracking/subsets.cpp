#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:

    void backtrack(vector<int>& nums ,vector<int>& current, vector<vector<int>>& result, int start){
          result.push_back(current);

        for(int i=start; i<nums.size();i++){
            current.push_back(nums[i]);
            backtrack(nums, current, result, i+1);
         current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> & nums){
        vector<int> current;
        vector<vector<int>> result;
        backtrack(nums, current, result,0);
        return result;
    }
    void print(vector<vector<int>>& ans) {

    for (const auto& row : ans) {

        for (int element : row) {
            cout << element << " ";
        }

        cout << endl;
    }
}
};

int main(){

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    Solution s;
   vector<vector<int>> subsets= s.subsets(nums);
   s.print(subsets);
return 0;
}