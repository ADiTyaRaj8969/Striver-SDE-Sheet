"""
Problem: Maximum Path Sum
Description: Find the maximum path sum in a binary tree. Path can start
             and end at any node.

Approach: At each node, calculate max path through it and update global max.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def maxPathSum(root: Optional[TreeNode]) -> int:
    max_sum = [float('-inf')]
    
    def helper(node):
        if not node:
            return 0
        
        left = max(0, helper(node.left))
        right = max(0, helper(node.right))
        
        max_sum[0] = max(max_sum[0], left + right + node.val)
        
        return node.val + max(left, right)
    
    helper(root)
    return max_sum[0]

def main():
    root = TreeNode(-10)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    
    print(maxPathSum(root))  # Output: 42

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
