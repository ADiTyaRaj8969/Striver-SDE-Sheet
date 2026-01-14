"""
Problem: Detect Cycle in Directed Graph
Description: Check if a directed graph contains a cycle.

Approach: Use DFS with recursion stack. Cycle exists if we visit a node that's
          currently in the recursion stack.
"""

from typing import List

def hasCycleDFS(node: int, adj: List[List[int]], visited: List[bool], recStack: List[bool]) -> bool:
    visited[node] = True
    recStack[node] = True
    
    for neighbor in adj[node]:
        if not visited[neighbor]:
            if hasCycleDFS(neighbor, adj, visited, recStack):
                return True
        elif recStack[neighbor]:
            return True
    
    recStack[node] = False
    return False

def detectCycle(V: int, adj: List[List[int]]) -> bool:
    visited = [False] * V
    recStack = [False] * V
    
    for i in range(V):
        if not visited[i]:
            if hasCycleDFS(i, adj, visited, recStack):
                return True
    
    return False

def main():
    V = 4
    adj = [[] for _ in range(V)]
    
    adj[0].append(1)
    adj[1].append(2)
    adj[2].append(3)
    adj[3].append(1)
    
    print(detectCycle(V, adj))  # Output: True

if __name__ == "__main__":
    main()

"""
Time Complexity: O(V + E)
Space Complexity: O(V)
"""
