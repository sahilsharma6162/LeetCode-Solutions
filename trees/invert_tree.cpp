#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
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
        vector<int> v;
        vector<int> invertTree(Node* root){
            if(root==nullptr){
                return v ;
            }
            else
            swap(root->left,root->right);
            v.push_back(root->data);
            invertTree(root->left);
            invertTree(root->right);
            
        return v;
        }
       void Print(vector<int> v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}
};

int main(){
     

Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution s;
    vector<int> result= s.invertTree(root);
    
    s.Print(result);

    return 0;
}