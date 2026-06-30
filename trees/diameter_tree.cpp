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
int maxi=0;
    int height(Node* root, int& maxi) {
        if (root == nullptr) return 0;

        int left_height = height(root->left, maxi);
        int right_height = height(root->right,maxi);

        maxi=  max(maxi,left_height+right_height);

        return 1 + max(left_height, right_height);
    }

};     

// separate solution for better handling of diameter..
// class Solution {
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         int diameter = 0;
//         height(root, diameter);
//         return diameter;
//     }

// private:
//     int height(TreeNode* node, int& diameter) {

//         if (!node) {
//             return 0;
//         }
//         int lh = height(node->left, diameter);
//         int rh = height(node->right, diameter);

//         diameter = max(diameter, lh + rh);

//         return 1 + max(lh, rh);
//     }
// };

int main() {
    
       Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution s;
    int max=0;

    s.height(root, max);

    cout <<"Diameter: "<< max << endl;
    
    return 0;
}