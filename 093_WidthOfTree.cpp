/*
Problem: Width of Binary Tree
Description: Find maximum width (max number of nodes at any level).

Approach: Use level order traversal with indexing to handle null gaps.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    
    int maxWidth = 0;
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        int size = q.size();
        long long minIndex = q.front().second;
        long long first, last;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front().first;
            long long index = q.front().second - minIndex;
            q.pop();
            
            if (i == 0) first = index;
            if (i == size - 1) last = index;
            
            if (node->left) q.push({node->left, 2 * index + 1});
            if (node->right) q.push({node->right, 2 * index + 2});
        }
        
        maxWidth = max(maxWidth, (int)(last - first + 1));
    }
    
    return maxWidth;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    
    cout << widthOfBinaryTree(root) << endl;  // Output: 2
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(w)
*/
