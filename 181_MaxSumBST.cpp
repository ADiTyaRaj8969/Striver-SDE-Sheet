/*
Problem: Maximum Sum BST in Binary Tree
Description: Find maximum sum of values in any BST subtree of a binary tree.

Approach: Post-order traversal. Track {isBST, min, max, sum} for each subtree.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Info {
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};

Info helper(TreeNode* root, int& maxSum) {
    if (!root) {
        return {true, INT_MAX, INT_MIN, 0};
    }
    
    Info left = helper(root->left, maxSum);
    Info right = helper(root->right, maxSum);
    
    Info curr;
    
    if (left.isBST && right.isBST && 
        root->val > left.maxVal && root->val < right.minVal) {
        curr.isBST = true;
        curr.minVal = min(root->val, left.minVal);
        curr.maxVal = max(root->val, right.maxVal);
        curr.sum = left.sum + right.sum + root->val;
        
        maxSum = max(maxSum, curr.sum);
    } else {
        curr.isBST = false;
        curr.sum = max(left.sum, right.sum);
    }
    
    return curr;
}

int maxSumBST(TreeNode* root) {
    int maxSum = 0;
    helper(root, maxSum);
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);
    
    cout << "Maximum sum BST: " << maxSumBST(root) << endl;
    // Output: 20
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
