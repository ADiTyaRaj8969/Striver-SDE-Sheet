"""
Problem: Width of Binary Tree
Description: Find maximum width (max number of nodes at any level).

Approach: Use level order traversal with indexing to handle null gaps.
"""

from typing import Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def widthOfBinaryTree(root: Optional[TreeNode]) -> int:
    if not root:
        return 0
    
    max_width = 0
    queue = deque([(root, 0)])
    
    while queue:
        size = len(queue)
        min_index = queue[0][1]
        first = last = 0
        
        for i in range(size):
            node, index = queue.popleft()
            index -= min_index
            
            if i == 0:
                first = index
            if i == size - 1:
                last = index
            
            if node.left:
                queue.append((node.left, 2 * index + 1))
            if node.right:
                queue.append((node.right, 2 * index + 2))
        
        max_width = max(max_width, last - first + 1)
    
    return max_width

def main():
    root = TreeNode(1)
    root.left = TreeNode(3)
    root.right = TreeNode(2)
    root.left.left = TreeNode(5)
    root.left.right = TreeNode(3)
    
    print(widthOfBinaryTree(root))  # Output: 2

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(w)
"""
