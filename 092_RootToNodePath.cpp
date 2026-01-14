/*
Problem: Root to Node Path
Description: Find path from root to a given node in a binary tree.

Approach: Use recursion to track path, backtrack if node not found.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool findPath(TreeNode* root, int target, vector<int>& path) {
    if (!root) return false;
    
    path.push_back(root->val);
    
    if (root->val == target) return true;
    
    if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
        return true;
    }
    
    path.pop_back();
    return false;
}

vector<int> rootToNodePath(TreeNode* root, int target) {
    vector<int> path;
    findPath(root, target, path);
    return path;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    vector<int> path = rootToNodePath(root, 5);
    for (int x : path) cout << x << " ";  // Output: 1 2 5
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
