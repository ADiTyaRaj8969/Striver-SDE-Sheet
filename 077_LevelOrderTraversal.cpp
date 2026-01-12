/*
Problem: Level Order Traversal
Description: Perform level order (breadth-first) traversal of a binary tree.

Approach: Use queue for BFS traversal level by level.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(level);
    }
    
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> result = levelOrder(root);
    for (auto& level : result) {
        for (int x : level) cout << x << " ";
        cout << endl;
    }
    // Output:
    // 3
    // 9 20
    // 15 7
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(w) where w is maximum width of tree
*/
