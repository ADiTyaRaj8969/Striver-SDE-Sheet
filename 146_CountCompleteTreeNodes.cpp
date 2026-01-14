/*
Problem: Count Complete Tree Nodes
Description: Count nodes in a complete binary tree efficiently.

Approach: Use tree completeness property. If left height == right height, tree
          is perfect with 2^h - 1 nodes. Else recurse on subtrees.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getLeftHeight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}

int getRightHeight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->right;
    }
    return height;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    
    int leftHeight = getLeftHeight(root);
    int rightHeight = getRightHeight(root);
    
    if (leftHeight == rightHeight) {
        return (1 << leftHeight) - 1;  // 2^h - 1
    }
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    
    cout << "Number of nodes: " << countNodes(root) << endl;  // Output: 6
    
    return 0;
}

/*
Time Complexity: O(log^2 n)
Space Complexity: O(log n)
*/
