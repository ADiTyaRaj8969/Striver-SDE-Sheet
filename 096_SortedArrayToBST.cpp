/*
Problem: Convert Sorted Array to BST
Description: Convert a sorted array to a height-balanced BST.

Approach: Use middle element as root, recursively build left and right subtrees.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);
    
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);
    
    inorder(root);  // Output: -10 -3 0 5 9
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(log n) for recursion
*/
