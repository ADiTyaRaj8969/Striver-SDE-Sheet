"""
Problem: Diameter of Binary Tree
Description: Find the longest path between any two nodes in a tree.

Approach: At each node, calculate diameter as left_height + right_height.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def diameterOfBinaryTree(root: Optional[TreeNode]) -> int:
    diameter = [0]
    
    def height(node):
        if not node:
            return 0
        
        left = height(node.left)
        right = height(node.right)
        
        diameter[0] = max(diameter[0], left + right)
        
        return 1 + max(left, right)
    
    height(root)
    return diameter[0]

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    
    print(diameterOfBinaryTree(root))  # Output: 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
