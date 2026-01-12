/*
Problem: Preorder Traversal
Description: Perform preorder traversal of a binary tree (Root-Left-Right).

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
void preorderHelper(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorderHelper(root->left, result);
    preorderHelper(root->right, result);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorderHelper(root, result);
    return result;
}

// Iterative approach
vector<int> preorderIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    vector<int> result = preorderTraversal(root);
    for (int x : result) cout << x << " ";  // Output: 1 2 3
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
