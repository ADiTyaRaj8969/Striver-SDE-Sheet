"""
Problem: Bottom View of Binary Tree
Description: Print the bottom view of a binary tree (last node at each horizontal distance).

Approach: Use level order traversal, update map for each horizontal distance.
"""

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def bottomView(root: Optional[TreeNode]) -> List[int]:
    if not root:
        return []
    
    bottom_nodes = {}
    queue = deque([(root, 0)])
    
    while queue:
        node, hd = queue.popleft()
        
        bottom_nodes[hd] = node.val
        
        if node.left:
            queue.append((node.left, hd - 1))
        if node.right:
            queue.append((node.right, hd + 1))
    
    return [bottom_nodes[key] for key in sorted(bottom_nodes.keys())]

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    
    print(bottomView(root))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
