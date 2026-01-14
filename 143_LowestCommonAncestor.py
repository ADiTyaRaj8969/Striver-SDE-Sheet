"""
Problem: Lowest Common Ancestor of Binary Tree
Description: Find lowest common ancestor of two nodes in binary tree.

Approach: Recursively search for both nodes. If current node is one of them or
          both are found in different subtrees, current node is LCA.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def lowestCommonAncestor(root: Optional[TreeNode], p: TreeNode, q: TreeNode) -> Optional[TreeNode]:
    if not root or root == p or root == q:
        return root
    
    left = lowestCommonAncestor(root.left, p, q)
    right = lowestCommonAncestor(root.right, p, q)
    
    if left and right:
        return root  # Both found in different subtrees
    
    return left if left else right  # Return non-null result

def main():
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(4)
    
    p = root.left  # Node 5
    q = root.right  # Node 1
    
    lca = lowestCommonAncestor(root, p, q)
    print("LCA:", lca.val)  # Output: 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
