"""
Problem: Kth Smallest Element in BST
Description: Find kth smallest element in Binary Search Tree.

Approach: Inorder traversal (iterative with stack). Return kth element visited.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Iterative approach
def kthSmallest(root: Optional[TreeNode], k: int) -> int:
    stack = []
    curr = root
    count = 0
    
    while curr or stack:
        while curr:
            stack.append(curr)
            curr = curr.left
        
        curr = stack.pop()
        count += 1
        
        if count == k:
            return curr.val
        
        curr = curr.right
    
    return -1

# Recursive approach
def kthSmallestRecursive(root: Optional[TreeNode], k: int) -> int:
    result = [-1]
    counter = [k]
    
    def inorder(node):
        if not node:
            return
        
        inorder(node.left)
        
        counter[0] -= 1
        if counter[0] == 0:
            result[0] = node.val
            return
        
        inorder(node.right)
    
    inorder(root)
    return result[0]

def main():
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.left.left.left = TreeNode(1)
    
    k = 3
    print(f"{k}th smallest: {kthSmallest(root, k)}")
    # Output: 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(h + k) where h is height
Space Complexity: O(h)
"""
