/*
Problem: Flatten Binary Tree to Linked List
Description: Flatten a binary tree to a linked list in-place (preorder).

Approach: Use Morris traversal or recursion with reverse preorder.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Approach 1: Using stack (preorder)
void flatten(TreeNode* root) {
    if (!root) return;
    
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
        
        if (!st.empty())
            curr->right = st.top();
        
        curr->left = nullptr;
    }
}

// Approach 2: Recursive (reverse preorder)
TreeNode* prev = nullptr;

void flattenRecursive(TreeNode* root) {
    if (!root) return;
    
    flattenRecursive(root->right);
    flattenRecursive(root->left);
    
    root->right = prev;
    root->left = nullptr;
    prev = root;
}

// Approach 3: Morris Traversal
void flattenMorris(TreeNode* root) {
    TreeNode* curr = root;
    
    while (curr) {
        if (curr->left) {
            TreeNode* pre = curr->left;
            while (pre->right)
                pre = pre->right;
            
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        
        curr = curr->right;
    }
}

void printList(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    
    flatten(root);
    
    cout << "Flattened tree: ";
    printList(root);  // Output: 1 2 3 4 5 6
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) for stack, O(h) for recursive, O(1) for Morris
*/
