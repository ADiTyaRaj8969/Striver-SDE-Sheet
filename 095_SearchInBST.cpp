/*
Problem: Search in BST
Description: Search for a value in a Binary Search Tree.

Approach: Use BST property - go left if smaller, right if larger.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    
    if (val < root->val) {
        return searchBST(root->left, val);
    }
    return searchBST(root->right, val);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    TreeNode* result = searchBST(root, 2);
    if (result) cout << "Found: " << result->val << endl;
    else cout << "Not found" << endl;
    
    return 0;
}

/*
Time Complexity: O(h) where h is height
Space Complexity: O(h) for recursion
*/
