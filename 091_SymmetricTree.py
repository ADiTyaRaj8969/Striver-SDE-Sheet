"""
Problem: Symmetric Tree
Description: Check if a binary tree is a mirror of itself (symmetric).

Approach: Recursively check if left subtree mirrors right subtree.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isMirror(left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
    if not left and not right:
        return True
    if not left or not right:
        return False
    
    return (left.val == right.val and
            isMirror(left.left, right.right) and
            isMirror(left.right, right.left))

def isSymmetric(root: Optional[TreeNode]) -> bool:
    if not root:
        return True
    return isMirror(root.left, root.right)

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(3)
    
    print(isSymmetric(root))  # Output: True

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
