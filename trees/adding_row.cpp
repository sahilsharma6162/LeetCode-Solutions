#include<iostream>
#include<queue>
#include <algorithm>
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
int target_depth;
      Node* addOneRow(Node* root, int val, int depth){
         target_depth=depth;
               if(depth==1){
                  Node* newRoot= new Node(val);
                  newRoot->left=root;
                  return newRoot;                            
               }

               newTree(root,val,1);
      }

      void newTree(Node* root,int& val, int current_depth){
        if(root==nullptr){
            return;
        }
        if(current_depth== target_depth-1){
            Node* oldLeft= root->left;
            Node* old_right= root->right;

            Node* newLeft= new Node(val);
            root->left=newLeft;
             Node* new_Right= new Node(val);
             root->right=new_Right;

             newLeft->left=oldLeft;
             new_Right->right=old_right;
             return;
        }
             newTree(root->left,val,current_depth+1);
            newTree(root->right,val,current_depth+1);
        
      }
};
