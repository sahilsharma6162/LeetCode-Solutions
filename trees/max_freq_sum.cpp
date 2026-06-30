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

    unordered_map<int,int> freq;
    vector<int> findFrequentTreeSum(Node* root) {

        int max_freq = 0;
        tree_sum(root, max_freq);

        vector<int> ans;

        for(auto it : freq) {

            if(it.second == max_freq) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }

    int tree_sum(Node* root, int& max_freq) {

        if(root == nullptr) {
            return 0;
        }
        int left_sum = tree_sum(root->left, max_freq);
        int right_sum = tree_sum(root->right, max_freq);

        int current_sum =
            root->data + left_sum + right_sum;

        freq[current_sum]++;

        max_freq = max(max_freq,
                       freq[current_sum]);
        return current_sum;
    }
};
