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
    vector<vector<int>> LevelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<Node*> q;
        q.push(root);
       bool lefttoright= true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                
                Node* current = q.front();
                q.pop();
                
                level.push_back(current->data);

                if (current->left != nullptr)
                    q.push(current->left);

                if (current->right != nullptr)
                    q.push(current->right);
            }
          if(lefttoright){
            reverse(level.begin(),level.end());
            
            ans.push_back(level);

        }
        else
          ans.push_back(level);
         lefttoright= !lefttoright;

        return ans;
    }
    
    void Print(vector<vector<int>>ans){
    for (auto level : ans) {

    for (auto node : level) {
        cout << node << " ";
    }

    cout << endl;
    }
  }

  int count(vector<vector<int>> ans) {
    int height = ans.size();
    cout << "the height of tree is: " << height << endl;
    return height;
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
    vector<vector<int>> result=s.LevelOrder(root);
    s.Print(result);
    cout<<endl;
    // reverse order
s.count(result);
    return 0;

}