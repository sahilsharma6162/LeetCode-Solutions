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
vector<int> ans;
     bool search_value(Node* root, int target){
        if(root== nullptr)
        return false;

        if(root->data==target)
        return true;

        if(root->data > target){
           search_value(root->left, target);
        }
        else search_value(root->right, target);

     }
};