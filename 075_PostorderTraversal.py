"""
Problem: Postorder Traversal
Description: Perform postorder traversal of a binary tree (Left-Right-Root).

Approach: Use recursive or iterative approach with two stacks.
"""

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Recursive approach
def postorderTraversal(root: Optional[TreeNode]) -> List[int]:
    result = []
    
    def helper(node):
        if not node:
            return
        helper(node.left)
        helper(node.right)
        result.append(node.val)
    
    helper(root)
    return result

# Iterative approach using two stacks
def postorderIterative(root: Optional[TreeNode]) -> List[int]:
    result = []
    if not root:
        return result
    
    stack1 = [root]
    stack2 = []
    
    while stack1:
        node = stack1.pop()
        stack2.append(node)
        
        if node.left:
            stack1.append(node.left)
        if node.right:
            stack1.append(node.right)
    
    while stack2:
        result.append(stack2.pop().val)
    
    return result

def main():
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    
    print(postorderTraversal(root))  # Output: [3, 2, 1]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
