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
      int preindex=0;
    Node* buildTree( vector<int>& inorder, vector<int>& preorder){
          return helper(inorder,preorder,0, inorder.size()-1);  
    }

    Node* helper(vector<int>& preorder, vector<int>& inorder,int inStart,int inEnd){
        if(inStart>inEnd){
            return nullptr;
        }
        int rootValue= preorder[preindex++];
        Node* root= new Node(rootValue);

        int pos=-1;
        for(int i=inStart; i<=inEnd; i++){
            if(inorder[i]==rootValue){
                pos=i;
                break;
            }
        }
             root->left =
            helper(preorder,
                   inorder,
                   inStart,
                   pos - 1);

        root->right =
            helper(preorder,
                   inorder,
                   pos + 1,
                   inEnd);

        return root;
    }
    };