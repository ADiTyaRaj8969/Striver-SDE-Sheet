/*
Problem: Boundary Traversal
Description: Print boundary nodes of a binary tree in anti-clockwise direction.

Approach: Print left boundary, leaves, then right boundary (bottom-up).
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isLeaf(TreeNode* node) {
    return !node->left && !node->right;
}

void addLeftBoundary(TreeNode* root, vector<int>& result) {
    TreeNode* curr = root->left;
    while (curr) {
        if (!isLeaf(curr)) result.push_back(curr->val);
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addLeaves(TreeNode* root, vector<int>& result) {
    if (!root) return;
    if (isLeaf(root)) {
        result.push_back(root->val);
        return;
    }
    addLeaves(root->left, result);
    addLeaves(root->right, result);
}

void addRightBoundary(TreeNode* root, vector<int>& result) {
    TreeNode* curr = root->right;
    vector<int> temp;
    while (curr) {
        if (!isLeaf(curr)) temp.push_back(curr->val);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        result.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    if (!isLeaf(root)) result.push_back(root->val);
    addLeftBoundary(root, result);
    addLeaves(root, result);
    addRightBoundary(root, result);
    
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    vector<int> result = boundaryTraversal(root);
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
