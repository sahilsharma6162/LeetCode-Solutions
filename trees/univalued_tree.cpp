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
    bool isUnivalTree(Node* root) {

        if (root == nullptr) {
            return true;
        }

        if (root->left != nullptr && root->data != root->left->data) {
            return false;
        }

        if (root->right != nullptr && root->data != root->right->data) {
            return false;
        }

        bool left_check = isUnivalTree(root->left);
        bool right_check = isUnivalTree(root->right);

        return left_check && right_check;
    }
};

int main() {

    Node* root = new Node(5);

    root->left = new Node(5);
    root->right = new Node(5);

    root->left->left = new Node(5);

    root->left->left->left = new Node(5);
    root->left->left->right = new Node(5);

    root->right->left = new Node(5);

    root->right->right = new Node(4);

    root->right->right->right = new Node(5);

    Solution s;
    if(s.isUnivalTree(root)){
        cout<<"the tree is univalued. " << endl;
    }
    else
    cout<<"the tree is not univalued. " << endl;
    
    return 0;
}
