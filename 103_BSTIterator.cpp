/*
Problem: BST Iterator
Description: Implement iterator for BST with next() and hasNext() methods.

Approach: Use stack to perform iterative inorder traversal.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;
    
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    
    BSTIterator iterator(root);
    cout << iterator.next() << endl;    // Output: 3
    cout << iterator.next() << endl;    // Output: 7
    cout << iterator.hasNext() << endl; // Output: 1
    cout << iterator.next() << endl;    // Output: 9
    
    return 0;
}

/*
Time Complexity: O(1) average for next()
Space Complexity: O(h)
*/
