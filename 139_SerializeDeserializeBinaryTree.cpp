/*
Problem: Serialize and Deserialize Binary Tree
Description: Design algorithm to serialize and deserialize a binary tree.

Approach: Use preorder traversal with null markers.
          Serialize: preorder with "null" for empty nodes
          Deserialize: reconstruct tree from preorder with queue
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string
    string serialize(TreeNode* root) {
        if (!root) return "null,";
        
        return to_string(root->val) + "," + 
               serialize(root->left) + 
               serialize(root->right);
    }
    
    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        string str = "";
        
        for (char c : data) {
            if (c == ',') {
                nodes.push(str);
                str = "";
            } else {
                str += c;
            }
        }
        
        return deserializeHelper(nodes);
    }
    
private:
    TreeNode* deserializeHelper(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        
        if (val == "null")
            return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(nodes);
        node->right = deserializeHelper(nodes);
        
        return node;
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;
    
    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Inorder of deserialized tree: ";
    inorder(deserialized);
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
