"""
Problem: Children Sum Property
Description: Check if sum of children equals parent value for all nodes.

Approach: Recursively check condition at each node.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isChildrenSum(root: Optional[TreeNode]) -> bool:
    if not root:
        return True
    
    if not root.left and not root.right:
        return True
    
    total = 0
    if root.left:
        total += root.left.val
    if root.right:
        total += root.right.val
    
    return (total == root.val and 
            isChildrenSum(root.left) and 
            isChildrenSum(root.right))

def main():
    root = TreeNode(10)
    root.left = TreeNode(8)
    root.right = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(5)
    
    print(isChildrenSum(root))  # Output: True

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
