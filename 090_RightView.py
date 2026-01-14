"""
Problem: Right View of Binary Tree
Description: Print the right view of a binary tree (last node at each level).

Approach: Use level order traversal, pick last node at each level.
"""

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def rightView(root: Optional[TreeNode]) -> List[int]:
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        size = len(queue)
        
        for i in range(size):
            node = queue.popleft()
            
            if i == size - 1:
                result.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
    
    return result

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    
    print(rightView(root))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(w)
"""
