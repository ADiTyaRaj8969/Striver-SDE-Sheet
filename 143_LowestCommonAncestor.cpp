/*
Problem: Lowest Common Ancestor of Binary Tree
Description: Find lowest common ancestor of two nodes in binary tree.

Approach: Recursively search for both nodes. If current node is one of them or
          both are found in different subtrees, current node is LCA.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q)
        return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right)
        return root;  // Both found in different subtrees
    
    return left ? left : right;  // Return non-null result
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    TreeNode* p = root->left;  // Node 5
    TreeNode* q = root->right;  // Node 1
    
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA: " << lca->val << endl;  // Output: 3
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
