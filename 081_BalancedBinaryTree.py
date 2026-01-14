"""
Problem: Check if Tree is Balanced
Description: Check if a binary tree is height-balanced (height difference
             of left and right subtrees <= 1 for all nodes).

Approach: Calculate height and check balance condition at each node.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isBalanced(root: Optional[TreeNode]) -> bool:
    def check_height(node):
        if not node:
            return 0
        
        left = check_height(node.left)
        if left == -1:
            return -1
        
        right = check_height(node.right)
        if right == -1:
            return -1
        
        if abs(left - right) > 1:
            return -1
        
        return 1 + max(left, right)
    
    return check_height(root) != -1

def main():
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    
    print(isBalanced(root))  # Output: True

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
