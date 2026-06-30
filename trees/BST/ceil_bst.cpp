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
int current_ceil=-1;
        int find_ceil(Node *root, int x){
              if(root==nullptr){
                return current_ceil;
              }
  if(root->data==x){
    current_ceil=root->data;
    return current_ceil;
     } 
  if(root->data>x){
    current_ceil=root->data;
   return find_ceil(root->left,x);
    }
    else return find_ceil(root->right, x);

  }
};

// function to find floor which is mirror image of ceil
// class Solution {
// public: 
// int current_ceil=-1;
//         int find_ceil(Node *root, int x){
//               if(root==nullptr){
//                 return current_ceil;
//               }
//   if(root->data==x){
//     current_ceil=root->data;
//     return current_ceil;
//      } 
//   if(root->data<x){
//     current_ceil=root->data;
//    return find_ceil(root->right,x);
//     }
//     else return find_ceil(root->left, x);

//   }
// };

