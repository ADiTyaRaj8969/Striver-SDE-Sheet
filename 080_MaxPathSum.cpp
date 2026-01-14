/*
Problem: Maximum Path Sum
Description: Find the maximum path sum in a binary tree. Path can start
             and end at any node.

Approach: At each node, calculate max path through it and update global max.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathHelper(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    
    int left = max(0, maxPathHelper(root->left, maxSum));
    int right = max(0, maxPathHelper(root->right, maxSum));
    
    maxSum = max(maxSum, left + right + root->val);
    
    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathHelper(root, maxSum);
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << maxPathSum(root) << endl;  // Output: 42
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
