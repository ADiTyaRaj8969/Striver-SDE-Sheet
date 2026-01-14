"""
Problem: All Nodes Distance K in Binary Tree
Description: Find all nodes at distance K from target node.

Approach: Build parent pointers, then BFS from target node to find all nodes
          at distance K (treat tree as undirected graph).
"""

from typing import Optional, List
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildParentMap(root: TreeNode, parent: dict):
    if not root:
        return
    
    if root.left:
        parent[root.left] = root
        buildParentMap(root.left, parent)
    
    if root.right:
        parent[root.right] = root
        buildParentMap(root.right, parent)

def distanceK(root: Optional[TreeNode], target: TreeNode, k: int) -> List[int]:
    parent = {}
    buildParentMap(root, parent)
    
    visited = set()
    q = deque([target])
    visited.add(target)
    
    distance = 0
    
    while q:
        if distance == k:
            break
        
        size = len(q)
        for _ in range(size):
            node = q.popleft()
            
            # Check left child
            if node.left and node.left not in visited:
                q.append(node.left)
                visited.add(node.left)
            
            # Check right child
            if node.right and node.right not in visited:
                q.append(node.right)
                visited.add(node.right)
            
            # Check parent
            if node in parent and parent[node] not in visited:
                q.append(parent[node])
                visited.add(parent[node])
        
        distance += 1
    
    return [node.val for node in q]

def main():
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(4)
    
    target = root.left  # Node 5
    k = 2
    
    result = distanceK(root, target, k)
    
    print(f"Nodes at distance {k}:", result)  # Output: [7, 4, 1]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
