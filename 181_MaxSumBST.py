"""
Problem: Maximum Sum BST in Binary Tree
Description: Find maximum sum of values in any BST subtree of a binary tree.

Approach: Post-order traversal. Track {isBST, min, max, sum} for each subtree.
"""

from typing import Optional, Tuple

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def helper(root: Optional[TreeNode], maxSum: list) -> Tuple[bool, int, int, int]:
    if not root:
        return (True, float('inf'), float('-inf'), 0)
    
    leftBST, leftMin, leftMax, leftSum = helper(root.left, maxSum)
    rightBST, rightMin, rightMax, rightSum = helper(root.right, maxSum)
    
    if leftBST and rightBST and root.val > leftMax and root.val < rightMin:
        currSum = leftSum + rightSum + root.val
        maxSum[0] = max(maxSum[0], currSum)
        return (True, min(root.val, leftMin), max(root.val, rightMax), currSum)
    else:
        return (False, 0, 0, max(leftSum, rightSum))

def maxSumBST(root: Optional[TreeNode]) -> int:
    maxSum = [0]
    helper(root, maxSum)
    return maxSum[0]

def main():
    root = TreeNode(1)
    root.left = TreeNode(4)
    root.right = TreeNode(3)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(2)
    root.right.right = TreeNode(5)
    root.right.right.left = TreeNode(4)
    root.right.right.right = TreeNode(6)
    
    print(f"Maximum sum BST: {maxSumBST(root)}")
    # Output: 20

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
