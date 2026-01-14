"""
Problem: Same Tree
Description: Check if two binary trees are identical.

Approach: Recursively compare structure and values.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isSameTree(p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    if not p and not q:
        return True
    if not p or not q:
        return False
    
    if p.val != q.val:
        return False
    
    return isSameTree(p.left, q.left) and isSameTree(p.right, q.right)

def main():
    p = TreeNode(1)
    p.left = TreeNode(2)
    p.right = TreeNode(3)
    
    q = TreeNode(1)
    q.left = TreeNode(2)
    q.right = TreeNode(3)
    
    print(isSameTree(p, q))  # Output: True

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
