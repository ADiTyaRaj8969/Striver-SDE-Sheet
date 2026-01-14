"""
Problem: Serialize and Deserialize Binary Tree
Description: Design algorithm to serialize and deserialize a binary tree.

Approach: Use preorder traversal with null markers.
          Serialize: preorder with "None" for empty nodes
          Deserialize: reconstruct tree from preorder with queue
"""

from typing import Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Codec:
    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string"""
        if not root:
            return "null,"
        
        return str(root.val) + "," + \
               self.serialize(root.left) + \
               self.serialize(root.right)
    
    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree"""
        nodes = deque(data.split(','))
        return self.deserializeHelper(nodes)
    
    def deserializeHelper(self, nodes: deque) -> Optional[TreeNode]:
        val = nodes.popleft()
        
        if val == "null" or val == "":
            return None
        
        node = TreeNode(int(val))
        node.left = self.deserializeHelper(nodes)
        node.right = self.deserializeHelper(nodes)
        
        return node

def inorder(root: TreeNode):
    if not root:
        return
    inorder(root.left)
    print(root.val, end=" ")
    inorder(root.right)

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(5)
    
    codec = Codec()
    serialized = codec.serialize(root)
    print("Serialized:", serialized)
    
    deserialized = codec.deserialize(serialized)
    print("Inorder of deserialized tree:", end=" ")
    inorder(deserialized)
    print()

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
