#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    bool findPath(Node* root, int target_sum, vector<int>& path) {
        if (root == nullptr) {
            return false;
        }

        path.push_back(root->data);
        target_sum -= root->data;

        if (root->left == nullptr && root->right == nullptr && target_sum == 0) {
            return true;
        }

        if (findPath(root->left, target_sum, path) || findPath(root->right, target_sum, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }
};

// class Solution {
// public:
//     void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
//         if (root == nullptr) return;

//         path.push_back(root->val);
//         targetSum -= root->val;

//         if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
//             ans.push_back(path);
//         } else {
//             dfs(root->left, targetSum, path, ans);
//             dfs(root->right, targetSum, path, ans);
//         }

//         path.pop_back();
//     }

//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>> ans;
//         vector<int> path;
//         dfs(root, targetSum, path, ans);
//         return ans;
//     }
// };

int main() {
    Node* root = new Node(5);

    root->left = new Node(4);
    root->right = new Node(8);

    root->left->left = new Node(11);

    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);

    root->right->left = new Node(13);
    root->right->right = new Node(4);

    root->right->right->right = new Node(1);

    Solution s;
    vector<int> path;

    if (s.findPath(root, 22, path)) {
        for (int x : path) {
            cout << x << " ";
        }
    } else {
        cout << "No path found";
    }

    return 0;
}