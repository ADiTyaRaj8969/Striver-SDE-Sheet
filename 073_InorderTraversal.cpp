/*
Problem: Inorder Traversal
Description: Perform inorder traversal of a binary tree (Left-Root-Right).

Approach: Use recursive or iterative approach with stack.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive approach
void inorderHelper(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderHelper(root->left, result);
    result.push_back(root->val);
    inorderHelper(root->right, result);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}

// Iterative approach
vector<int> inorderIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    vector<int> result = inorderTraversal(root);
    for (int x : result) cout << x << " ";  // Output: 1 3 2
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h) for recursion stack or explicit stack
*/
