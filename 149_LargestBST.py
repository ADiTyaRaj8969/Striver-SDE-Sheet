"""
Problem: Largest BST in Binary Tree
Description: Find size of largest BST subtree in a binary tree.

Approach: For each node, check if subtree is BST and track size.
          Return {isBST, size, min, max} for each subtree.
"""

from typing import Optional, Tuple

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def largestBSTHelper(root: Optional[TreeNode], maxSize: list) -> Tuple[bool, int, int, int]:
    if not root:
        return (True, 0, float('inf'), float('-inf'))
    
    leftBST, leftSize, leftMin, leftMax = largestBSTHelper(root.left, maxSize)
    rightBST, rightSize, rightMin, rightMax = largestBSTHelper(root.right, maxSize)
    
    if leftBST and rightBST and root.val > leftMax and root.val < rightMin:
        size = leftSize + rightSize + 1
        maxSize[0] = max(maxSize[0], size)
        return (True, size, min(root.val, leftMin), max(root.val, rightMax))
    else:
        return (False, max(leftSize, rightSize), float('-inf'), float('inf'))

def largestBST(root: Optional[TreeNode]) -> int:
    maxSize = [0]
    largestBSTHelper(root, maxSize)
    return maxSize[0]

def main():
    root = TreeNode(10)
    root.left = TreeNode(5)
    root.right = TreeNode(15)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(8)
    root.right.right = TreeNode(7)
    
    print("Size of largest BST:", largestBST(root))  # Output: 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
