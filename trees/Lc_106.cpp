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
    Node* buildTree( vector<int>& inorder, vector<int>& postorder){
                int postIndex = postorder.size() - 1;

          return helper(postorder,inorder,0, inorder.size()-1,postIndex);  
    }

    Node* helper(vector<int>& postorder, vector<int>& inorder,int inStart,int inEnd, int& postIndex){
        if(inStart>inEnd){
            return nullptr;
        }
      int rootValue = postorder[postIndex--];
        Node* root= new Node(rootValue);

        int pos=-1;
        for(int i=inStart; i<=inEnd; i++){
            if(inorder[i]==rootValue){
                pos=i;
                break;
            }
        }
         root->right =
            helper(postorder,
                   inorder,
                   pos + 1,
                   inEnd, postIndex);      

             root->left =
            helper(postorder,
                   inorder,
                   inStart,
                   pos - 1, postIndex);

        return root;
    }
    };