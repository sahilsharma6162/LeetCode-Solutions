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

class Solution{
   public:
   bool isSymmetric(Node* root){
     if(root== nullptr){
        return true;
     }
     isSymmetriccheck(root->left, root->right);
   }

   bool isSymmetriccheck(Node* left, Node* right){
    if(left== nullptr && right== nullptr ){
        return true;
    }
    else return false;
    if(left->data== right->data){
        return true;
    }
    return isSymmetriccheck(left->left,right->right) && isSymmetriccheck(left->right,right->left);
   }
};

