"""
Problem: Level Order Traversal
Description: Perform level order (breadth-first) traversal of a binary tree.

Approach: Use queue for BFS traversal level by level.
"""

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def levelOrder(root: Optional[TreeNode]) -> List[List[int]]:
    result = []
    if not root:
        return result
    
    queue = deque([root])
    
    while queue:
        level = []
        size = len(queue)
        
        for _ in range(size):
            node = queue.popleft()
            level.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(level)
    
    return result

def main():
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    
    print(levelOrder(root))
    # Output: [[3], [9, 20], [15, 7]]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(w) where w is maximum width of tree
"""
