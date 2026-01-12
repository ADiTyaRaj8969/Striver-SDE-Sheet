"""
Problem: Height of Binary Tree
Description: Find the maximum depth/height of a binary tree.

Approach: Use recursion to calculate height as 1 + max(left_height, right_height).
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def maxDepth(root: Optional[TreeNode]) -> int:
    if not root:
        return 0
    return 1 + max(maxDepth(root.left), maxDepth(root.right))

def main():
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    
    print(maxDepth(root))  # Output: 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h) for recursion stack
"""
