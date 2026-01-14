/*
Problem: Diameter of Binary Tree
Description: Find the longest path between any two nodes in a tree.

Approach: At each node, calculate diameter as left_height + right_height.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int diameterHelper(TreeNode* root, int& diameter) {
    if (!root) return 0;
    
    int left = diameterHelper(root->left, diameter);
    int right = diameterHelper(root->right, diameter);
    
    diameter = max(diameter, left + right);
    
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    diameterHelper(root, diameter);
    return diameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << diameterOfBinaryTree(root) << endl;  // Output: 3
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
