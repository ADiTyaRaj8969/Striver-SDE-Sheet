"""
Problem: Validate BST
Description: Check if a binary tree is a valid Binary Search Tree.

Approach: Use range validation - each node must be within (min, max) bounds.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isValidBST(root: Optional[TreeNode]) -> bool:
    def validate(node, min_val, max_val):
        if not node:
            return True
        
        if node.val <= min_val or node.val >= max_val:
            return False
        
        return (validate(node.left, min_val, node.val) and
                validate(node.right, node.val, max_val))
    
    return validate(root, float('-inf'), float('inf'))

def main():
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    
    print(isValidBST(root))  # Output: True
    
    root2 = TreeNode(5)
    root2.left = TreeNode(1)
    root2.right = TreeNode(4)
    root2.right.left = TreeNode(3)
    root2.right.right = TreeNode(6)
    
    print(isValidBST(root2))  # Output: False

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
