"""
Problem: Binary Tree Maximum Path Sum
Description: Find maximum path sum where path can start and end at any node.

Approach: For each node, calculate max gain from left and right subtrees.
          Update global max with node.val + leftGain + rightGain.
          Return node.val + max(leftGain, rightGain) to parent.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def maxPathSumHelper(root: Optional[TreeNode], maxSum: list) -> int:
    if not root:
        return 0
    
    # Get max gain from left and right (ignore negative paths)
    leftGain = max(0, maxPathSumHelper(root.left, maxSum))
    rightGain = max(0, maxPathSumHelper(root.right, maxSum))
    
    # Path through current node
    pathSum = root.val + leftGain + rightGain
    
    # Update global maximum
    maxSum[0] = max(maxSum[0], pathSum)
    
    # Return max gain if we include current node
    return root.val + max(leftGain, rightGain)

def maxPathSum(root: Optional[TreeNode]) -> int:
    maxSum = [float('-inf')]
    maxPathSumHelper(root, maxSum)
    return maxSum[0]

def main():
    root = TreeNode(-10)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    
    print("Maximum path sum:", maxPathSum(root))  # Output: 42

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h) for recursion stack
"""
