/*
Problem: Height of Binary Tree
Description: Find the maximum depth/height of a binary tree.

Approach: Use recursion to calculate height as 1 + max(left_height, right_height).
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << maxDepth(root) << endl;  // Output: 3
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h) for recursion stack
*/
