#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution{
public:

    void inorder(TreeNode* root, vector<int>& ans){

        if(root == nullptr)
            return;

        inorder(root->left, ans);

        ans.push_back(root->val);

        inorder(root->right, ans);
    }

    int kthSmallest(TreeNode* root, int k){

        vector<int> ans;

        inorder(root, ans);

        return ans[k - 1];
    }
};

int main(){

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution s;

    int k = 4;

    cout << "The kth smallest value is: "
         << s.kthSmallest(root, k);

    return 0;
}