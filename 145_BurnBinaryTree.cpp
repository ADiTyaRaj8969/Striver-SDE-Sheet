/*
Problem: Minimum Time to Burn Binary Tree
Description: Find minimum time to burn entire binary tree starting from target node.
             Fire spreads to adjacent nodes (left, right, parent) in 1 unit time.

Approach: Similar to distance K problem. BFS from target with parent pointers.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildParentMap(TreeNode* root, int target, unordered_map<TreeNode*, TreeNode*>& parent) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* targetNode = nullptr;
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node->val == target)
            targetNode = node;
        
        if (node->left) {
            parent[node->left] = node;
            q.push(node->left);
        }
        
        if (node->right) {
            parent[node->right] = node;
            q.push(node->right);
        }
    }
    
    return targetNode;
}

int minTimeToBurn(TreeNode* root, int target) {
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* targetNode = buildParentMap(root, target, parent);
    
    unordered_set<TreeNode*> visited;
    queue<TreeNode*> q;
    q.push(targetNode);
    visited.insert(targetNode);
    
    int time = 0;
    
    while (!q.empty()) {
        int size = q.size();
        bool burned = false;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left && !visited.count(node->left)) {
                q.push(node->left);
                visited.insert(node->left);
                burned = true;
            }
            
            if (node->right && !visited.count(node->right)) {
                q.push(node->right);
                visited.insert(node->right);
                burned = true;
            }
            
            if (parent.count(node) && !visited.count(parent[node])) {
                q.push(parent[node]);
                visited.insert(parent[node]);
                burned = true;
            }
        }
        
        if (burned) time++;
    }
    
    return time;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    
    int target = 8;
    cout << "Minimum time to burn: " << minTimeToBurn(root, target) << endl;  // Output: 4
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
