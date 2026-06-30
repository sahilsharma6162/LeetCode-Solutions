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

class Solution {
public:
        int totaltilt(Node* root){
               int total_tilt=0;
               calc_tilt(root,total_tilt);
               return total_tilt;
        }

        int calc_tilt(Node*root, int& total_tilt){
            
            if (root==nullptr){
                return 0;
            }
            
            int left_sum= calc_tilt(root->left, total_tilt);
            int right_sum= calc_tilt(root->right, total_tilt);

            int current_tilt= abs(left_sum-right_sum);

            total_tilt+= current_tilt;

            return root->data+left_sum+right_sum;
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
    int total_tilt=0;

    s.totaltilt(root );

    cout <<"Total Tilt is: "<< total_tilt << endl;
    
    return 0;
}