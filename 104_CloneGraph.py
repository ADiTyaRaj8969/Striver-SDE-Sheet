"""
Problem: Clone Graph
Description: Create a deep copy of an undirected graph.

Approach: Use DFS/BFS with hash map to track cloned nodes.
"""

from typing import Optional

class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

def cloneGraph(node: Optional[Node]) -> Optional[Node]:
    if not node:
        return None
    
    visited = {}
    
    def dfs(node):
        if node in visited:
            return visited[node]
        
        clone = Node(node.val)
        visited[node] = clone
        
        for neighbor in node.neighbors:
            clone.neighbors.append(dfs(neighbor))
        
        return clone
    
    return dfs(node)

def main():
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    node4 = Node(4)
    
    node1.neighbors = [node2, node4]
    node2.neighbors = [node1, node3]
    node3.neighbors = [node2, node4]
    node4.neighbors = [node1, node3]
    
    cloned = cloneGraph(node1)
    print("Graph cloned successfully")

if __name__ == "__main__":
    main()

"""
Time Complexity: O(V + E)
Space Complexity: O(V)
"""
