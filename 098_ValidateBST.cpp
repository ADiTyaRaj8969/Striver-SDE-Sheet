/*
Problem: Validate BST
Description: Check if a binary tree is a valid Binary Search Tree.

Approach: Use range validation - each node must be within (min, max) bounds.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    
    if (root->val <= minVal || root->val >= maxVal) {
        return false;
    }
    
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    cout << isValidBST(root) << endl;  // Output: 1 (true)
    
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    
    cout << isValidBST(root2) << endl;  // Output: 0 (false)
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
