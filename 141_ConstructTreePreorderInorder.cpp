/*
Problem: Construct Binary Tree from Preorder and Inorder
Description: Build binary tree from preorder and inorder traversal arrays.

Approach: First element of preorder is root. Find root in inorder to split
          into left and right subtrees. Recursively build left and right.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                          vector<int>& inorder, int inStart, int inEnd,
                          unordered_map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;
    
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);
    
    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart;
    
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inMap);
    
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    
    return buildTreeHelper(preorder, 0, preorder.size() - 1,
                          inorder, 0, inorder.size() - 1, inMap);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    TreeNode* root = buildTree(preorder, inorder);
    
    cout << "Inorder traversal: ";
    printInorder(root);
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
