/*
Problem: Postorder Traversal
Description: Perform postorder traversal of a binary tree (Left-Right-Root).

Approach: Use recursive or iterative approach with two stacks.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive approach
void postorderHelper(TreeNode* root, vector<int>& result) {
    if (!root) return;
    postorderHelper(root->left, result);
    postorderHelper(root->right, result);
    result.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    postorderHelper(root, result);
    return result;
}

// Iterative approach using two stacks
vector<int> postorderIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    stack<TreeNode*> st1, st2;
    st1.push(root);
    
    while (!st1.empty()) {
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);
        
        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }
    
    while (!st2.empty()) {
        result.push_back(st2.top()->val);
        st2.pop();
    }
    
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    vector<int> result = postorderTraversal(root);
    for (int x : result) cout << x << " ";  // Output: 3 2 1
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
