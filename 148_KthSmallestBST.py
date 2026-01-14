"""
Problem: Kth Smallest Element in BST
Description: Find kth smallest element in BST.

Approach: Inorder traversal gives sorted order. Track count and return kth element.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorder(root: TreeNode, k: int, count: list, result: list):
    if not root or count[0] >= k:
        return
    
    inorder(root.left, k, count, result)
    
    count[0] += 1
    if count[0] == k:
        result[0] = root.val
        return
    
    inorder(root.right, k, count, result)

def kthSmallest(root: Optional[TreeNode], k: int) -> int:
    count = [0]
    result = [-1]
    inorder(root, k, count, result)
    return result[0]

# Iterative approach
def kthSmallestIterative(root: Optional[TreeNode], k: int) -> int:
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

def main():
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.left.left.left = TreeNode(1)
    
    k = 3
    print("Kth smallest:", kthSmallest(root, k))  # Output: 3
    print("Kth smallest (iterative):", kthSmallestIterative(root, k))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n) worst case, O(k) average
Space Complexity: O(h)
"""
