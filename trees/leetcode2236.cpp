#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution{
    public:
bool checkTree( Node* root){
    if(root==nullptr){
        return false;
    }

    if(root->left!= nullptr && root->right!= nullptr){
        if(
            root->data== root->left->data+ root->right->data
        )
        return true;
    }
    checkTree(root->left);
    checkTree(root->right);
  }
};

int main() {

    Node* root = new Node(5);

    root->left = new Node(2);
    root->right = new Node(4);

    // root->left->left = new Node(5);

    // root->left->left->left = new Node(5);
    // root->left->left->right = new Node(5);

    // root->right->left = new Node(5);

    // root->right->right = new Node(5);

    // root->right->right->right = new Node(5);

    Solution s;
    if(s.checkTree(root)){
        cout<<"the tree is good. " << endl;
    }
    else
    cout<<"the tree is not good. " << endl;
    
    return 0;
}