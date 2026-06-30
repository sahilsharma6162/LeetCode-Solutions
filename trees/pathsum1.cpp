#include<iostream>
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

class Solution{
    public:
    bool findPath(Node* root, int target_sum){
            int remaining;

           if(root==nullptr){
            return false;
           }
           remaining=target_sum - root->data;
           if(root->left==nullptr  &&root->right==nullptr && remaining==0){
            return true;
           }
           else{

        bool leftans=   findPath(root-> left, remaining);
       bool rightans=  findPath(root-> right, remaining);
     return leftans||rightans;
    }
    }
};

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
    
    
    return 0;
}

