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

      if(root->data >p->data && root->data>q->data){
            return lowestCommonAncestor(root->left,p,q);
      }
      if(root->data <p->data && root->data<q->data){
            return lowestCommonAncestor(root->right,p,q);
      }
      return root;
    }
};

int main() {

    Node* root = new Node(3);

    root->left = new Node(5);
    root->right = new Node(1);

    root->left->left = new Node(6);
    root->left->right = new Node(2);

    root->right->left = new Node(0);
    root->right->right = new Node(8);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Node* p = root->left;
    Node* q = root->right;

    Solution s;

    Node* ans = s.lowestCommonAncestor(root, p, q);

    cout << "LCA = " << ans->data << endl;

    return 0;
}