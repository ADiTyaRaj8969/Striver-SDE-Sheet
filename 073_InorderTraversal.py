"""
Problem: Inorder Traversal
Description: Perform inorder traversal of a binary tree (Left-Root-Right).

Approach: Use recursive or iterative approach with stack.
"""

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Recursive approach
def inorderTraversal(root: Optional[TreeNode]) -> List[int]:
    result = []
    
    def helper(node):
        if not node:
            return
        helper(node.left)
        result.append(node.val)
        helper(node.right)
    
    helper(root)
    return result

# Iterative approach
def inorderIterative(root: Optional[TreeNode]) -> List[int]:
    result = []
    stack = []
    curr = root
    
    while curr or stack:
        while curr:
            stack.append(curr)
            curr = curr.left
        curr = stack.pop()
        result.append(curr.val)
        curr = curr.right
    
    return result

def main():
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    
    print(inorderTraversal(root))  # Output: [1, 3, 2]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h) for recursion stack or explicit stack
"""
