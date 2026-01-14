"""
Problem: Left View of Binary Tree
Description: Print the left view of a binary tree (first node at each level).

Approach: Use level order traversal, pick first node at each level.
"""

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def leftView(root: Optional[TreeNode]) -> List[int]:
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        size = len(queue)
        
        for i in range(size):
            node = queue.popleft()
            
            if i == 0:
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
    
    print(leftView(root))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(w)
"""
