"""
Problem: Predecessor and Successor in BST
Description: Find inorder predecessor and successor of a given key in BST.

Approach: Use BST property to find predecessor (largest in left) and successor (smallest in right).
"""

from typing import Optional, Tuple

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def findPreSucc(root: Optional[TreeNode], key: int) -> Tuple[Optional[TreeNode], Optional[TreeNode]]:
    pred = None
    succ = None
    
    # Find predecessor
    curr = root
    while curr:
        if curr.val >= key:
            curr = curr.left
        else:
            pred = curr
            curr = curr.right
    
    # Find successor
    curr = root
    while curr:
        if curr.val <= key:
            curr = curr.right
        else:
            succ = curr
            curr = curr.left
    
    return pred, succ

def main():
    root = TreeNode(50)
    root.left = TreeNode(30)
    root.right = TreeNode(70)
    root.left.left = TreeNode(20)
    root.left.right = TreeNode(40)
    root.right.left = TreeNode(60)
    root.right.right = TreeNode(80)
    
    pred, succ = findPreSucc(root, 50)
    if pred:
        print(f"Predecessor: {pred.val}")
    if succ:
        print(f"Successor: {succ.val}")

if __name__ == "__main__":
    main()

"""
Time Complexity: O(h)
Space Complexity: O(1)
"""
