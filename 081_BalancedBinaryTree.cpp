/*
Problem: Check if Tree is Balanced
Description: Check if a binary tree is height-balanced (height difference
             of left and right subtrees <= 1 for all nodes).

Approach: Calculate height and check balance condition at each node.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int checkHeight(TreeNode* root, bool& balanced) {
    if (!root) return 0;
    
    int left = checkHeight(root->left, balanced);
    int right = checkHeight(root->right, balanced);
    
    if (abs(left - right) > 1) {
        balanced = false;
    }
    
    return 1 + max(left, right);
}

bool isBalanced(TreeNode* root) {
    bool balanced = true;
    checkHeight(root, balanced);
    return balanced;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << isBalanced(root) << endl;  // Output: 1 (true)
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
