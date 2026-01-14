"""
Problem: Lowest Common Ancestor (LCA)
Description: Find the lowest common ancestor of two nodes in a binary tree.

Approach: Recursively search for nodes. LCA is where both are found in
          different subtrees or one is ancestor of other.
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
        return root
    
    return left if left else right

def main():
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)
    
    lca = lowestCommonAncestor(root, root.left, root.right)
    print(lca.val)  # Output: 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""
