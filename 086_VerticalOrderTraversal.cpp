/*
Problem: Vertical Order Traversal
Description: Print vertical order traversal of a binary tree.

Approach: Use map with horizontal distance as key, perform level order traversal.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        
        nodes[x][y].insert(node->val);
        
        if (node->left) q.push({node->left, {x - 1, y + 1}});
        if (node->right) q.push({node->right, {x + 1, y + 1}});
    }
    
    for (auto& p : nodes) {
        vector<int> col;
        for (auto& q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        result.push_back(col);
    }
    
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    vector<vector<int>> result = verticalTraversal(root);
    for (auto& col : result) {
        for (int x : col) cout << x << " ";
        cout << endl;
    }
    
    return 0;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
