/*
Problem: Construct Binary Tree from Postorder and Inorder
Description: Build binary tree from postorder and inorder traversal arrays.

Approach: Last element of postorder is root. Find root in inorder to split
          into left and right subtrees. Recursively build right then left.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeHelper(vector<int>& postorder, int postStart, int postEnd,
                          vector<int>& inorder, int inStart, int inEnd,
                          unordered_map<int, int>& inMap) {
    if (postStart > postEnd || inStart > inEnd)
        return nullptr;
    
    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);
    
    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart;
    
    root->left = buildTreeHelper(postorder, postStart, postStart + numsLeft - 1,
                                 inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeHelper(postorder, postStart + numsLeft, postEnd - 1,
                                  inorder, inRoot + 1, inEnd, inMap);
    
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    
    return buildTreeHelper(postorder, 0, postorder.size() - 1,
                          inorder, 0, inorder.size() - 1, inMap);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    
    TreeNode* root = buildTree(inorder, postorder);
    
    cout << "Inorder traversal: ";
    printInorder(root);
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
