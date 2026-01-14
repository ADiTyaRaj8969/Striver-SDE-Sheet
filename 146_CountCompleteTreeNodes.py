"""
Problem: Count Complete Tree Nodes
Description: Count nodes in a complete binary tree efficiently.

Approach: Use tree completeness property. If left height == right height, tree
          is perfect with 2^h - 1 nodes. Else recurse on subtrees.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def getLeftHeight(node: TreeNode) -> int:
    height = 0
    while node:
        height += 1
        node = node.left
    return height

def getRightHeight(node: TreeNode) -> int:
    height = 0
    while node:
        height += 1
        node = node.right
    return height

def countNodes(root: Optional[TreeNode]) -> int:
    if not root:
        return 0
    
    leftHeight = getLeftHeight(root)
    rightHeight = getRightHeight(root)
    
    if leftHeight == rightHeight:
        return (1 << leftHeight) - 1  # 2^h - 1
    
    return 1 + countNodes(root.left) + countNodes(root.right)

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    
    print("Number of nodes:", countNodes(root))  # Output: 6

if __name__ == "__main__":
    main()

"""
Time Complexity: O(log^2 n)
Space Complexity: O(log n)
"""
