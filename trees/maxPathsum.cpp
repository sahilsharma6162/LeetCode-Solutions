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
    int maxPathSum(Node* root) {
        int maxi = 0;
        maxSum(root, maxi);
        return maxi;
    }

private:
    int maxSum(Node* node, int& maxi) {
        if (!node) {
            return 0;
        }

        int ls = maxSum(node->left, maxi);
        int rs = maxSum(node->right, maxi);

        maxi = max(maxi, node->data + ls + rs);

        return node->data + max(ls, rs);
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution s;
    cout << "Max Path Sum: " << s.maxPathSum(root) << endl;

    return 0;
}