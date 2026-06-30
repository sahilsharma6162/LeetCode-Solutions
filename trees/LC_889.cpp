#include<iostream>
#include<algorithm>
#include<vector>
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

    int pre_index = 0;

    Node* construct_tree(vector<int>& preorder,
                         vector<int>& postorder) {

        return buildTree(preorder,
                         postorder,
                         0,
                         postorder.size() - 1);
    }

    Node* buildTree(vector<int>& preorder,
                    vector<int>& postorder,
                    int postStart,
                    int postEnd) {

        if (postStart > postEnd) {
            return nullptr;
        }
        int rootValue = preorder[pre_index++];
        Node* root = new Node(rootValue);

        if (postStart == postEnd) {
            return root;
        }
        int pos = -1;
        for (int i = postStart; i <= postEnd; i++) {
            if (postorder[i] == preorder[pre_index]) {
                pos = i;
                break;
            }
        }

        int left_size = pos - postStart + 1;
       root->left= buildTree(preorder, postorder, postStart, pos);
        root->right= buildTree(preorder, postorder, pos + 1, postEnd - 1);
        
      return root;
    }
};