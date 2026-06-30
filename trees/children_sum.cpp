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
    bool isfollowing(Node* root) {

        if (root == nullptr) {
            return true;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }

        int left_value = 0;
        int right_value = 0;

        if (root->left != nullptr) {
            left_value = root->left->data;
        }

        if (root->right != nullptr) {
            right_value = root->right->data;
        }

        bool current_check =
            (root->data == left_value + right_value);

        bool left_check = isfollowing(root->left);

        bool right_check = isfollowing(root->right);

        return current_check &&
               left_check &&
               right_check;
    }
};