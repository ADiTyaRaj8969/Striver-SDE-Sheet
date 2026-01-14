/*
Problem: LCA in BST
Description: Find lowest common ancestor in Binary Search Tree.

Approach: Use BST property to navigate - if both nodes on same side, go that way.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    
    return root;
}

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    TreeNode* lca = lowestCommonAncestor(root, root->left, root->right);
    cout << lca->val << endl;  // Output: 6
    
    return 0;
}

/*
Time Complexity: O(h)
Space Complexity: O(h)
*/
