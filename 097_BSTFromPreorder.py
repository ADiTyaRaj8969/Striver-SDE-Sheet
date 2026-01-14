"""
Problem: Construct BST from Preorder
Description: Construct a BST from its preorder traversal.

Approach: First element is root, partition remaining by value, recursively build.
"""

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def bstFromPreorder(preorder: List[int]) -> Optional[TreeNode]:
    def helper(bound: int) -> Optional[TreeNode]:
        if not preorder or preorder[0] > bound:
            return None
        
        root = TreeNode(preorder.pop(0))
        root.left = helper(root.val)
        root.right = helper(bound)
        
        return root
    
    return helper(float('inf'))

def inorder(root: Optional[TreeNode]):
    if not root:
        return
    inorder(root.left)
    print(root.val, end=" ")
    inorder(root.right)

def main():
    preorder = [8, 5, 1, 7, 10, 12]
    root = bstFromPreorder(preorder)
    
    inorder(root)  # Output: 1 5 7 8 10 12
    print()

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
