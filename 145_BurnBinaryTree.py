"""
Problem: Minimum Time to Burn Binary Tree
Description: Find minimum time to burn entire binary tree starting from target node.
             Fire spreads to adjacent nodes (left, right, parent) in 1 unit time.

Approach: Similar to distance K problem. BFS from target with parent pointers.
"""

from typing import Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildParentMap(root: TreeNode, target: int, parent: dict) -> Optional[TreeNode]:
    q = deque([root])
    targetNode = None
    
    while q:
        node = q.popleft()
        
        if node.val == target:
            targetNode = node
        
        if node.left:
            parent[node.left] = node
            q.append(node.left)
        
        if node.right:
            parent[node.right] = node
            q.append(node.right)
    
    return targetNode

def minTimeToBurn(root: Optional[TreeNode], target: int) -> int:
    parent = {}
    targetNode = buildParentMap(root, target, parent)
    
    visited = set()
    q = deque([targetNode])
    visited.add(targetNode)
    
    time = 0
    
    while q:
        size = len(q)
        burned = False
        
        for _ in range(size):
            node = q.popleft()
            
            if node.left and node.left not in visited:
                q.append(node.left)
                visited.add(node.left)
                burned = True
            
            if node.right and node.right not in visited:
                q.append(node.right)
                visited.add(node.right)
                burned = True
            
            if node in parent and parent[node] not in visited:
                q.append(parent[node])
                visited.add(parent[node])
                burned = True
        
        if burned:
            time += 1
    
    return time

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(6)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(8)
    
    target = 8
    print("Minimum time to burn:", minTimeToBurn(root, target))  # Output: 4

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
