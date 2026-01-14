/*
Problem: Kth Smallest in BST
Description: Find the kth smallest element in a Binary Search Tree.

Approach: Inorder traversal gives sorted order, return kth element.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, int& k, int& result) {
    if (!root || k == 0) return;
    
    inorder(root->left, k, result);
    
    k--;
    if (k == 0) {
        result = root->val;
        return;
    }
    
    inorder(root->right, k, result);
}

int kthSmallest(TreeNode* root, int k) {
    int result = -1;
    inorder(root, k, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    
    cout << kthSmallest(root, 1) << endl;  // Output: 1
    cout << kthSmallest(root, 2) << endl;  // Output: 2
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
