/*
Problem: Kth Smallest Element in BST
Description: Find kth smallest element in BST.

Approach: Inorder traversal gives sorted order. Track count and return kth element.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, int k, int& count, int& result) {
    if (!root || count >= k) return;
    
    inorder(root->left, k, count, result);
    
    count++;
    if (count == k) {
        result = root->val;
        return;
    }
    
    inorder(root->right, k, count, result);
}

int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    inorder(root, k, count, result);
    return result;
}

// Iterative approach
int kthSmallestIterative(TreeNode* root, int k) {
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
        
        if (count == k)
            return curr->val;
        
        curr = curr->right;
    }
    
    return -1;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    
    int k = 3;
    cout << "Kth smallest: " << kthSmallest(root, k) << endl;  // Output: 3
    cout << "Kth smallest (iterative): " << kthSmallestIterative(root, k) << endl;
    
    return 0;
}

/*
Time Complexity: O(n) worst case, O(k) average
Space Complexity: O(h)
*/
