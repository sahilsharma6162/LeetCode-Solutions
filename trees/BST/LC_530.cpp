#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
 void inorder(TreeNode* root, vector<int>& ans){

        if(root == nullptr)
            return;

        inorder(root->left, ans);

        ans.push_back(root->data);

        inorder(root->right, ans);
    }
   int minDiff=INT_MAX;
    int getMinimumDifference(TreeNode* root) {
       
        vector<int> ans;
        inorder(root, ans);
  for(int i=1;i<=ans.size()-1;i++){
        minDiff=min( minDiff,ans[i]-ans[i-1]);

  }
return minDiff;
    }
};