"""
Problem: Morris Inorder Traversal
Description: Perform inorder traversal without using stack or recursion.

Approach: Use threaded binary tree concept. Create temporary links to successor.
"""

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def morrisInorder(root: Optional[TreeNode]) -> List[int]:
    result = []
    curr = root
    
    while curr:
        if not curr.left:
            result.append(curr.val)
            curr = curr.right
        else:
            pred = curr.left
            while pred.right and pred.right != curr:
                pred = pred.right
            
            if not pred.right:
                pred.right = curr
                curr = curr.left
            else:
                pred.right = None
                result.append(curr.val)
                curr = curr.right
    
    return result

def main():
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    
    print(morrisInorder(root))  # Output: [1, 3, 2]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""
