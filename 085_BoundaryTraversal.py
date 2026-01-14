"""
Problem: Boundary Traversal
Description: Print boundary nodes of a binary tree in anti-clockwise direction.

Approach: Print left boundary, leaves, then right boundary (bottom-up).
"""

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isLeaf(node: TreeNode) -> bool:
    return not node.left and not node.right

def addLeftBoundary(root: TreeNode, result: List[int]):
    curr = root.left
    while curr:
        if not isLeaf(curr):
            result.append(curr.val)
        if curr.left:
            curr = curr.left
        else:
            curr = curr.right

def addLeaves(root: Optional[TreeNode], result: List[int]):
    if not root:
        return
    if isLeaf(root):
        result.append(root.val)
        return
    addLeaves(root.left, result)
    addLeaves(root.right, result)

def addRightBoundary(root: TreeNode, result: List[int]):
    curr = root.right
    temp = []
    while curr:
        if not isLeaf(curr):
            temp.append(curr.val)
        if curr.right:
            curr = curr.right
        else:
            curr = curr.left
    result.extend(reversed(temp))

def boundaryTraversal(root: Optional[TreeNode]) -> List[int]:
    result = []
    if not root:
        return result
    
    if not isLeaf(root):
        result.append(root.val)
    addLeftBoundary(root, result)
    addLeaves(root, result)
    addRightBoundary(root, result)
    
    return result

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    
    print(boundaryTraversal(root))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
