/*
Problem: Binary Tree Maximum Path Sum
Description: Find maximum path sum where path can start and end at any node.

Approach: For each node, calculate max gain from left and right subtrees.
          Update global max with node->val + leftGain + rightGain.
          Return node->val + max(leftGain, rightGain) to parent.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathSumHelper(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    
    // Get max gain from left and right (ignore negative paths)
    int leftGain = max(0, maxPathSumHelper(root->left, maxSum));
    int rightGain = max(0, maxPathSumHelper(root->right, maxSum));
    
    // Path through current node
    int pathSum = root->val + leftGain + rightGain;
    
    // Update global maximum
    maxSum = max(maxSum, pathSum);
    
    // Return max gain if we include current node
    return root->val + max(leftGain, rightGain);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << "Maximum path sum: " << maxPathSum(root) << endl;  // Output: 42
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h) for recursion stack
*/
