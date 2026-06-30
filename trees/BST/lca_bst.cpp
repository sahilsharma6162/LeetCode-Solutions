#include<iostream>
#include<stack>
#include<vector>
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
    Node* lowestCommonAncestor(Node* root, Node* p,Node* q){

      if(root==nullptr){
        return nullptr;
      }

      if(root==p || root==q){
        return root;
      }

      Node* left = lowestCommonAncestor(root->left, p, q);
        Node* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        if (left != nullptr) {
            return left;
        }
        return right;
    }
};
