#include<iostream>
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

// inorder traversal
// void inorder(Node* root) {
//     if (root == nullptr) return;

//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }


// pre order traversal
// void Preorder(Node* root) {
//     if (root == nullptr) return;

//     cout << root->data << " ";
//     Preorder(root->left);
//     Preorder(root->right);
// }

void Postorder(Node* root) {
    if (root == nullptr) return;

    Postorder(root->left);
    Postorder(root->right);   
     cout << root->data << " ";

}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);  
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    Postorder(root);
    return 0;
}