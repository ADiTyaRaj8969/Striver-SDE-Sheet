"""
Problem: Vertical Order Traversal
Description: Print vertical order traversal of a binary tree.

Approach: Use dictionary with horizontal distance as key, perform level order traversal.
"""

from typing import List, Optional
from collections import deque, defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def verticalTraversal(root: Optional[TreeNode]) -> List[List[int]]:
    if not root:
        return []
    
    nodes = defaultdict(lambda: defaultdict(list))
    queue = deque([(root, 0, 0)])
    
    while queue:
        node, x, y = queue.popleft()
        nodes[x][y].append(node.val)
        
        if node.left:
            queue.append((node.left, x - 1, y + 1))
        if node.right:
            queue.append((node.right, x + 1, y + 1))
    
    result = []
    for x in sorted(nodes.keys()):
        col = []
        for y in sorted(nodes[x].keys()):
            col.extend(sorted(nodes[x][y]))
        result.append(col)
    
    return result

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    
    print(verticalTraversal(root))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n)
Space Complexity: O(n)
"""
