/*
Problem: All Nodes Distance K in Binary Tree
Description: Find all nodes at distance K from target node.

Approach: Build parent pointers, then BFS from target node to find all nodes
          at distance K (treat tree as undirected graph).
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void buildParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    if (!root) return;
    
    if (root->left) {
        parent[root->left] = root;
        buildParentMap(root->left, parent);
    }
    
    if (root->right) {
        parent[root->right] = root;
        buildParentMap(root->right, parent);
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;
    buildParentMap(root, parent);
    
    unordered_set<TreeNode*> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited.insert(target);
    
    int distance = 0;
    
    while (!q.empty()) {
        if (distance == k) break;
        
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            // Check left child
            if (node->left && !visited.count(node->left)) {
                q.push(node->left);
                visited.insert(node->left);
            }
            
            // Check right child
            if (node->right && !visited.count(node->right)) {
                q.push(node->right);
                visited.insert(node->right);
            }
            
            // Check parent
            if (parent.count(node) && !visited.count(parent[node])) {
                q.push(parent[node]);
                visited.insert(parent[node]);
            }
        }
        
        distance++;
    }
    
    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front()->val);
        q.pop();
    }
    
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    TreeNode* target = root->left;  // Node 5
    int k = 2;
    
    vector<int> result = distanceK(root, target, k);
    
    cout << "Nodes at distance " << k << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;  // Output: 7 4 1
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
