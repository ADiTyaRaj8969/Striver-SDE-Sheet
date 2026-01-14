"""
Problem: LCA in BST
Description: Find lowest common ancestor in Binary Search Tree.

Approach: Use BST property to navigate - if both nodes on same side, go that way.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def lowestCommonAncestor(root: Optional[TreeNode], p: TreeNode, q: TreeNode) -> Optional[TreeNode]:
    if not root:
        return None
    
    if p.val < root.val and q.val < root.val:
        return lowestCommonAncestor(root.left, p, q)
    
    if p.val > root.val and q.val > root.val:
        return lowestCommonAncestor(root.right, p, q)
    
    return root

def main():
    root = TreeNode(6)
    root.left = TreeNode(2)
    root.right = TreeNode(8)
    root.left.left = TreeNode(0)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(7)
    root.right.right = TreeNode(9)
    
    lca = lowestCommonAncestor(root, root.left, root.right)
    print(lca.val)  # Output: 6

if __name__ == "__main__":
    main()

"""
Time Complexity: O(h)
Space Complexity: O(h)
"""
