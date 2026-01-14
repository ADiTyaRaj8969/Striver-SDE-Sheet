/*
Problem: Construct BST from Preorder
Description: Construct a BST from its preorder traversal.

Approach: First element is root, partition remaining by value, recursively build.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* bstFromPreorder(vector<int>& preorder, int& index, int bound) {
    if (index >= preorder.size() || preorder[index] > bound) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(preorder[index++]);
    root->left = bstFromPreorder(preorder, index, root->val);
    root->right = bstFromPreorder(preorder, index, bound);
    
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int index = 0;
    return bstFromPreorder(preorder, index, INT_MAX);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode* root = bstFromPreorder(preorder);
    
    inorder(root);  // Output: 1 5 7 8 10 12
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
