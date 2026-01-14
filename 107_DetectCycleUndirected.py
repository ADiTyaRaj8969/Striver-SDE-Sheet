"""
Problem: Detect Cycle in Undirected Graph
Description: Check if an undirected graph contains a cycle.

Approach: Use DFS with parent tracking. Cycle exists if we visit a visited node
          that's not the parent.
"""

from typing import List

def hasCycleDFS(node: int, parent: int, adj: List[List[int]], visited: List[bool]) -> bool:
    visited[node] = True
    
    for neighbor in adj[node]:
        if not visited[neighbor]:
            if hasCycleDFS(neighbor, node, adj, visited):
                return True
        elif neighbor != parent:
            return True
    
    return False

def detectCycle(V: int, adj: List[List[int]]) -> bool:
    visited = [False] * V
    
    for i in range(V):
        if not visited[i]:
            if hasCycleDFS(i, -1, adj, visited):
                return True
    
    return False

def main():
    V = 5
    adj = [[] for _ in range(V)]
    
    adj[0].append(1)
    adj[1].append(0)
    adj[1].append(2)
    adj[2].append(1)
    adj[2].append(3)
    adj[3].append(2)
    adj[3].append(4)
    adj[4].append(3)
    adj[4].append(1)
    adj[1].append(4)
    
    print(detectCycle(V, adj))  # Output: True

if __name__ == "__main__":
    main()

"""
Time Complexity: O(V + E)
Space Complexity: O(V)
"""
