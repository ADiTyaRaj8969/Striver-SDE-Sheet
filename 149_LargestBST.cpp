/*
Problem: Largest BST in Binary Tree
Description: Find size of largest BST subtree in a binary tree.

Approach: For each node, check if subtree is BST and track size.
          Return {isBST, size, min, max} for each subtree.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

Info largestBSTHelper(TreeNode* root, int& maxSize) {
    if (!root) {
        return {true, 0, INT_MAX, INT_MIN};
    }
    
    Info left = largestBSTHelper(root->left, maxSize);
    Info right = largestBSTHelper(root->right, maxSize);
    
    Info curr;
    
    if (left.isBST && right.isBST && 
        root->val > left.maxVal && root->val < right.minVal) {
        curr.isBST = true;
        curr.size = left.size + right.size + 1;
        curr.minVal = min(root->val, left.minVal);
        curr.maxVal = max(root->val, right.maxVal);
        
        maxSize = max(maxSize, curr.size);
    } else {
        curr.isBST = false;
        curr.size = max(left.size, right.size);
        curr.minVal = INT_MIN;
        curr.maxVal = INT_MAX;
    }
    
    return curr;
}

int largestBST(TreeNode* root) {
    int maxSize = 0;
    largestBSTHelper(root, maxSize);
    return maxSize;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    
    cout << "Size of largest BST: " << largestBST(root) << endl;  // Output: 3
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)
*/
