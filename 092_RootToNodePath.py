"""
Problem: Root to Node Path
Description: Find path from root to a given node in a binary tree.

Approach: Use recursion to track path, backtrack if node not found.
"""

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def findPath(root: Optional[TreeNode], target: int, path: List[int]) -> bool:
    if not root:
        return False
    
    path.append(root.val)
    
    if root.val == target:
        return True
    
    if findPath(root.left, target, path) or findPath(root.right, target, path):
        return True
    
    path.pop()
    return False

def rootToNodePath(root: Optional[TreeNode], target: int) -> List[int]:
    path = []
    findPath(root, target, path)
    return path

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    
    print(rootToNodePath(root, 5))  # Output: [1, 2, 5]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
