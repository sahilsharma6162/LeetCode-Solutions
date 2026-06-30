#include<iostream>
#include<stack>
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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* current = st.top();
            st.pop();

            if (current->left != nullptr)
                st.push(current->left);

            if (current->right != nullptr)
                st.push(current->right);

          ans.push_back(current->data);

        }

        return ans;
    }

    void Print(vector<int>& ans) {
        for (auto node : ans) {
            cout << node << " ";
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
    vector<int> result=s.postorder(root);
    cout<<endl;
    // reverse order
    reverse(result.begin(), result.end());
    s.Print(result);
    return 0;


    return 0;
}