"""
Problem: Convert Sorted Array to BST
Description: Convert a sorted array to a height-balanced BST.

Approach: Use middle element as root, recursively build left and right subtrees.
"""

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sortedArrayToBST(nums: List[int]) -> Optional[TreeNode]:
    def helper(left: int, right: int) -> Optional[TreeNode]:
        if left > right:
            return None
        
        mid = left + (right - left) // 2
        root = TreeNode(nums[mid])
        
        root.left = helper(left, mid - 1)
        root.right = helper(mid + 1, right)
        
        return root
    
    return helper(0, len(nums) - 1)

def inorder(root: Optional[TreeNode]):
    if not root:
        return
    inorder(root.left)
    print(root.val, end=" ")
    inorder(root.right)

def main():
    nums = [-10, -3, 0, 5, 9]
    root = sortedArrayToBST(nums)
    
    inorder(root)  # Output: -10 -3 0 5 9
    print()

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(log n) for recursion
"""
