"""
Problem: Flatten Binary Tree to Linked List
Description: Flatten a binary tree to a linked list in-place (preorder).

Approach: Use Morris traversal or recursion with reverse preorder.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Approach 1: Using stack (preorder)
def flatten(root: Optional[TreeNode]) -> None:
    if not root:
        return
    
    stack = [root]
    
    while stack:
        curr = stack.pop()
        
        if curr.right:
            stack.append(curr.right)
        if curr.left:
            stack.append(curr.left)
        
        if stack:
            curr.right = stack[-1]
        
        curr.left = None

# Approach 2: Recursive (reverse preorder)
prev = None

def flattenRecursive(root: Optional[TreeNode]) -> None:
    global prev
    if not root:
        return
    
    flattenRecursive(root.right)
    flattenRecursive(root.left)
    
    root.right = prev
    root.left = None
    prev = root

# Approach 3: Morris Traversal
def flattenMorris(root: Optional[TreeNode]) -> None:
    curr = root
    
    while curr:
        if curr.left:
            pre = curr.left
            while pre.right:
                pre = pre.right
            
            pre.right = curr.right
            curr.right = curr.left
            curr.left = None
        
        curr = curr.right

def printList(root: TreeNode):
    values = []
    while root:
        values.append(root.val)
        root = root.right
    print(values)

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(5)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(6)
    
    flatten(root)
    
    print("Flattened tree:", end=" ")
    printList(root)  # Output: [1, 2, 3, 4, 5, 6]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n) for stack, O(h) for recursive, O(1) for Morris
"""
