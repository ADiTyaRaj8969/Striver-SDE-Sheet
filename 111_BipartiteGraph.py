"""
Problem: Bipartite Graph
Description: Check if a graph is bipartite. A bipartite graph can be colored using
             two colors such that no two adjacent vertices have the same color.

Approach: Use BFS/DFS with coloring. Try to color the graph with two colors.
          If we find adjacent vertices with same color, graph is not bipartite.
"""

from typing import List
from collections import deque

def bfsCheck(start: int, adj: List[List[int]], color: List[int]) -> bool:
    q = deque([start])
    color[start] = 0
    
    while q:
        node = q.popleft()
        
        for neighbor in adj[node]:
            if color[neighbor] == -1:
                color[neighbor] = 1 - color[node]
                q.append(neighbor)
            elif color[neighbor] == color[node]:
                return False
    
    return True

def isBipartite(V: int, adj: List[List[int]]) -> bool:
    color = [-1] * V
    
    for i in range(V):
        if color[i] == -1:
            if not bfsCheck(i, adj, color):
                return False
    
    return True

def main():
    V = 4
    adj = [[] for _ in range(V)]
    
    adj[0].append(1)
    adj[1].append(0)
    adj[1].append(2)
    adj[2].append(1)
    adj[2].append(3)
    adj[3].append(2)
    adj[3].append(0)
    adj[0].append(3)
    
    if isBipartite(V, adj):
        print("Graph is Bipartite")
    else:
        print("Graph is not Bipartite")

if __name__ == "__main__":
    main()

"""
Time Complexity: O(V + E)
Space Complexity: O(V)
"""
