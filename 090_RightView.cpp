/*
Problem: Right View of Binary Tree
Description: Print the right view of a binary tree (last node at each level).

Approach: Use level order traversal, pick last node at each level.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> rightView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (i == size - 1) result.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    vector<int> result = rightView(root);
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(w)
*/
