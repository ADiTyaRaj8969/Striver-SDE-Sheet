"""
Problem: Zigzag Level Order Traversal
Description: Perform zigzag (alternating left-to-right and right-to-left)
             level order traversal.

Approach: Use BFS with flag to alternate direction at each level.
"""

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def zigzagLevelOrder(root: Optional[TreeNode]) -> List[List[int]]:
    result = []
    if not root:
        return result
    
    queue = deque([root])
    left_to_right = True
    
    while queue:
        size = len(queue)
        level = [0] * size
        
        for i in range(size):
            node = queue.popleft()
            
            index = i if left_to_right else size - 1 - i
            level[index] = node.val
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        left_to_right = not left_to_right
        result.append(level)
    
    return result

def main():
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    
    print(zigzagLevelOrder(root))
    # Output: [[3], [20, 9], [15, 7]]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(w)
"""
