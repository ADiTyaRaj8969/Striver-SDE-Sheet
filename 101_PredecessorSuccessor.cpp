/*
Problem: Predecessor and Successor in BST
Description: Find inorder predecessor and successor of a given key in BST.

Approach: Use BST property to find predecessor (largest in left) and successor (smallest in right).
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

pair<TreeNode*, TreeNode*> findPreSucc(TreeNode* root, int key) {
    TreeNode *pred = nullptr, *succ = nullptr;
    
    // Find predecessor
    TreeNode* curr = root;
    while (curr) {
        if (curr->val >= key) {
            curr = curr->left;
        } else {
            pred = curr;
            curr = curr->right;
        }
    }
    
    // Find successor
    curr = root;
    while (curr) {
        if (curr->val <= key) {
            curr = curr->right;
        } else {
            succ = curr;
            curr = curr->left;
        }
    }
    
    return {pred, succ};
}

int main() {
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);
    
    auto [pred, succ] = findPreSucc(root, 50);
    if (pred) cout << "Predecessor: " << pred->val << endl;
    if (succ) cout << "Successor: " << succ->val << endl;
    
    return 0;
}

/*
Time Complexity: O(h)
Space Complexity: O(1)
*/
