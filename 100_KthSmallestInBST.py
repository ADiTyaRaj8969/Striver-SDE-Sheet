"""
Problem: Kth Smallest in BST
Description: Find the kth smallest element in a Binary Search Tree.

Approach: Inorder traversal gives sorted order, return kth element.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def kthSmallest(root: Optional[TreeNode], k: int) -> int:
    def inorder(node):
        if not node:
            return
        
        yield from inorder(node.left)
        yield node.val
        yield from inorder(node.right)
    
    for i, val in enumerate(inorder(root), 1):
        if i == k:
            return val
    
    return -1

def main():
    root = TreeNode(3)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.left.right = TreeNode(2)
    
    print(kthSmallest(root, 1))  # Output: 1
    print(kthSmallest(root, 2))  # Output: 2

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
