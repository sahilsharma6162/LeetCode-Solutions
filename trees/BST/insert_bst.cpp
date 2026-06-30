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

class Solution {
public:
     Node * insert(Node* root, int x){
        if(root==nullptr){
            Node* current= new Node(x);
        return current;
        }
        if(root->data>x){
          root->right=  insert(root->right,x);
        }
        if(root->data<x){
           root->left= insert(root->left,x);
        }

        return root;
     }
};