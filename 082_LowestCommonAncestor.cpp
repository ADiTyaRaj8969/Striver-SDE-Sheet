/*
Problem: Lowest Common Ancestor (LCA)
Description: Find the lowest common ancestor of two nodes in a binary tree.

Approach: Recursively search for nodes. LCA is where both are found in
          different subtrees or one is ancestor of other.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
        return root;
    }
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right) return root;
    
    return left ? left : right;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    
    TreeNode* lca = lowestCommonAncestor(root, root->left, root->right);
    cout << lca->val << endl;  // Output: 3
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
