/*
Problem: Children Sum Property
Description: Check if sum of children equals parent value for all nodes.

Approach: Recursively check condition at each node.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isChildrenSum(TreeNode* root) {
    if (!root) return true;
    
    if (!root->left && !root->right) return true;
    
    int sum = 0;
    if (root->left) sum += root->left->val;
    if (root->right) sum += root->right->val;
    
    return (sum == root->val) && 
           isChildrenSum(root->left) && 
           isChildrenSum(root->right);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    cout << isChildrenSum(root) << endl;  // Output: 1 (true)
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
