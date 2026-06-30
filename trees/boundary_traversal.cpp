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

        vector<int> getleftboundary(Node* root){
            vector <int> v;
             if(root==nullptr){
                return v;
             }
             Node* current= root->left;
          while(current!=nullptr){
            if(current->left!=nullptr || current->right!=nullptr){
          v.push_back(current->data);
        }

          if(current->left!= nullptr){
           current=current->left;
         }
         else
         current=current->right;
        }
        return v;
    }

vector<int> getrightboundary(Node* root){
            vector <int> v;
             if(root==nullptr){
                return v;
             }
             Node* current= root->right;
          while(current!=nullptr){
            if(current->left!=nullptr && current->right!=nullptr){
          v.push_back(current->data);
        }

          if(current->right!= nullptr){
           current=current->right;
         }
         else
         current=current->left;
        }
        return v;
    }

vector<int> getleaves(Node* root) {
    vector<int> v;

    if (root == nullptr) {
        return v;
    }

    if (root->left == nullptr && root->right == nullptr) {
        v.push_back(root->data);
        return v;
    }

    vector<int> leftLeaves = getleaves(root->left);
    vector<int> rightLeaves = getleaves(root->right);

    v.insert(v.end(), leftLeaves.begin(), leftLeaves.end());
    v.insert(v.end(), rightLeaves.begin(), rightLeaves.end());

    return v;
}
void Print(vector<int> ans) {
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
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
    vector<int> v1= s.getleftboundary(root);
    vector<int> v2= s.getleaves(root);
    vector<int> v3= s.getrightboundary(root);
    vector<int> ans;

     ans.insert(ans.end(), v1.begin(), v1.end());
     ans.insert(ans.end(), v2.begin(), v2.end());
     ans.insert(ans.end(), v3.begin(), v3.end());
     cout<<root->data;
     cout<<" ";
    s.Print(ans);
    return 0;
}