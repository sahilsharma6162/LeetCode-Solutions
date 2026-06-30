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

    int leftHeight(Node* root) {
        int height = 0;

        while (root != nullptr) {
            height++;
            root = root->left;
        }

        return height;
    }

    int rightHeight(Node* root) {
        int height = 0;

        while (root != nullptr) {
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(Node* root) {

        if (root == nullptr) {
            return 0;
        }

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if (lh == rh) {
            return (1 << lh) - 1;
        }

        return 1 +
               countNodes(root->left) +
               countNodes(root->right);
    }
};