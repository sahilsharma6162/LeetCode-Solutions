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
  TreeNode* first = nullptr;
  TreeNode* second = nullptr;
  TreeNode* prev = nullptr;

  void recoverTree(TreeNode* root){
    if (root == nullptr) return;

    recoverTree(root->left);
    cout << root->data << " ";

  if(prev != nullptr && prev->data > root->data)
 {
    if(first==nullptr){
    first=prev;
   second=root;
  }
  else 
  second=root;
}
    prev=root;
    recoverTree(root->right);


   }
}
;