/*
Problem: Kth Smallest Element in BST
Description: Find kth smallest element in Binary Search Tree.

Approach: Inorder traversal (iterative with stack). Return kth element visited.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Iterative approach
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* curr = root;
    int count = 0;
    
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        
        curr = st.top();
        st.pop();
        count++;
        
        if (count == k) {
            return curr->val;
        }
        
        curr = curr->right;
    }
    
    return -1;
}

// Recursive approach
void inorder(TreeNode* root, int& k, int& result) {
    if (!root) return;
    
    inorder(root->left, k, result);
    
    k--;
    if (k == 0) {
        result = root->val;
        return;
    }
    
    inorder(root->right, k, result);
}

int kthSmallestRecursive(TreeNode* root, int k) {
    int result = -1;
    inorder(root, k, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    
    int k = 3;
    cout << k << "th smallest: " << kthSmallest(root, k) << endl;
    // Output: 3
    
    return 0;
}

/*
Time Complexity: O(h + k) where h is height
Space Complexity: O(h)
*/
