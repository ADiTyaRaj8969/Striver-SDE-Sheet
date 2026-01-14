"""
Problem: Search in BST
Description: Search for a value in a Binary Search Tree.

Approach: Use BST property - go left if smaller, right if larger.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def searchBST(root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
    if not root or root.val == val:
        return root
    
    if val < root.val:
        return searchBST(root.left, val)
    return searchBST(root.right, val)

def main():
    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(7)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)
    
    result = searchBST(root, 2)
    if result:
        print(f"Found: {result.val}")
    else:
        print("Not found")

if __name__ == "__main__":
    main()

"""
Time Complexity: O(h) where h is height
Space Complexity: O(h) for recursion
"""
