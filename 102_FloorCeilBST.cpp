/*
Problem: Floor and Ceil in BST
Description: Find floor (largest value <= key) and ceil (smallest value >= key) in BST.

Approach: Use BST property to navigate and track closest values.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findFloor(TreeNode* root, int key) {
    int floor = -1;
    
    while (root) {
        if (root->val == key) {
            return root->val;
        } else if (root->val < key) {
            floor = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    
    return floor;
}

int findCeil(TreeNode* root, int key) {
    int ceil = -1;
    
    while (root) {
        if (root->val == key) {
            return root->val;
        } else if (root->val > key) {
            ceil = root->val;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    
    return ceil;
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    
    cout << "Floor of 5: " << findFloor(root, 5) << endl;   // Output: 4
    cout << "Ceil of 5: " << findCeil(root, 5) << endl;     // Output: 6
    
    return 0;
}

/*
Time Complexity: O(h)
Space Complexity: O(1)
*/
