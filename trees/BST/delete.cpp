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

    Node* deleteNode(Node* root, int key){

        if(root == nullptr)
            return nullptr;

        if(key < root->data)
            root->left = deleteNode(root->left, key);

        else if(key > root->data)
            root->right = deleteNode(root->right, key);

        else{

            if(root->left == nullptr && root->right == nullptr)
                return nullptr;

            if(root->left == nullptr)
                return root->right;

            if(root->right == nullptr)
                return root->left;

            Node* current = root->right;

            while(current->left != nullptr){
                current = current->left;
            }

            root->data = current->data;

            root->right = deleteNode(root->right, current->data);
        }

        return root;
    }
};