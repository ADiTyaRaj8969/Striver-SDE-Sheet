"""
Problem: Floor and Ceil in BST
Description: Find floor (largest value <= key) and ceil (smallest value >= key) in BST.

Approach: Use BST property to navigate and track closest values.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def findFloor(root: Optional[TreeNode], key: int) -> int:
    floor = -1
    
    while root:
        if root.val == key:
            return root.val
        elif root.val < key:
            floor = root.val
            root = root.right
        else:
            root = root.left
    
    return floor

def findCeil(root: Optional[TreeNode], key: int) -> int:
    ceil = -1
    
    while root:
        if root.val == key:
            return root.val
        elif root.val > key:
            ceil = root.val
            root = root.left
        else:
            root = root.right
    
    return ceil

def main():
    root = TreeNode(8)
    root.left = TreeNode(4)
    root.right = TreeNode(12)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(6)
    root.right.left = TreeNode(10)
    root.right.right = TreeNode(14)
    
    print(f"Floor of 5: {findFloor(root, 5)}")  # Output: 4
    print(f"Ceil of 5: {findCeil(root, 5)}")    # Output: 6

if __name__ == "__main__":
    main()

"""
Time Complexity: O(h)
Space Complexity: O(1)
"""
