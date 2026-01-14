"""
Problem: Top View of Binary Tree
Description: Print the top view of a binary tree (first node at each horizontal distance).

Approach: Use level order traversal with horizontal distance tracking.
"""

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def topView(root: Optional[TreeNode]) -> List[int]:
    if not root:
        return []
    
    top_nodes = {}
    queue = deque([(root, 0)])
    
    while queue:
        node, hd = queue.popleft()
        
        if hd not in top_nodes:
            top_nodes[hd] = node.val
        
        if node.left:
            queue.append((node.left, hd - 1))
        if node.right:
            queue.append((node.right, hd + 1))
    
    return [top_nodes[key] for key in sorted(top_nodes.keys())]

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    
    print(topView(root))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
