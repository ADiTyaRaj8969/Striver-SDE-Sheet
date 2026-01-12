"""
Problem: Preorder Traversal
Description: Perform preorder traversal of a binary tree (Root-Left-Right).

Approach: Use recursive or iterative approach with stack.
"""

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Recursive approach
def preorderTraversal(root: Optional[TreeNode]) -> List[int]:
    result = []
    
    def helper(node):
        if not node:
            return
        result.append(node.val)
        helper(node.left)
        helper(node.right)
    
    helper(root)
    return result

# Iterative approach
def preorderIterative(root: Optional[TreeNode]) -> List[int]:
    result = []
    if not root:
        return result
    
    stack = [root]
    
    while stack:
        node = stack.pop()
        result.append(node.val)
        
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)
    
    return result

def main():
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    
    print(preorderTraversal(root))  # Output: [1, 2, 3]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
