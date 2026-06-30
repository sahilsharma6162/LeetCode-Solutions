#include<iostream>
#include<vector>
#include<algorithm>
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
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
        if (root == nullptr) return;

        path.push_back(root->data);
        targetSum -= root->data;

        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            ans.push_back(path);
        } else {
            dfs(root->left, targetSum, path, ans);
            dfs(root->right, targetSum, path, ans);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }

    
};
int main() {
    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);

    root->right->right->right = new TreeNode(1);

    Solution s;
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> result= s.pathSum(root,22);
 cout<< "The number of paths are: "<< result.size()<< endl;
    return 0;
}