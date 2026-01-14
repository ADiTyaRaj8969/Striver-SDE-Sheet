/*
Problem: Top View of Binary Tree
Description: Print the top view of a binary tree (first node at each horizontal distance).

Approach: Use level order traversal with horizontal distance tracking.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> topView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    map<int, int> topNodes;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int hd = p.second;
        
        if (topNodes.find(hd) == topNodes.end()) {
            topNodes[hd] = node->val;
        }
        
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }
    
    for (auto& p : topNodes) {
        result.push_back(p.second);
    }
    
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    vector<int> result = topView(root);
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
