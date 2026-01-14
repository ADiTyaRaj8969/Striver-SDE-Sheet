/*
Problem: Same Tree
Description: Check if two binary trees are identical.

Approach: Recursively compare structure and values.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    
    if (p->val != q->val) return false;
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    
    cout << isSameTree(p, q) << endl;  // Output: 1 (true)
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
