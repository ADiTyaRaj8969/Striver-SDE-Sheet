"""
Problem: Topological Sort
Description: Find a linear ordering of vertices in a directed acyclic graph (DAG)
             such that for every directed edge u->v, u comes before v.

Approach: Use DFS and push nodes to stack after visiting all neighbors.
          Alternative: Kahn's algorithm (BFS with indegree).
"""

from typing import List
from collections import deque

def dfs(node: int, adj: List[List[int]], visited: List[bool], stack: List[int]):
    visited[node] = True
    
    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs(neighbor, adj, visited, stack)
    
    stack.append(node)

def topologicalSort(V: int, adj: List[List[int]]) -> List[int]:
    visited = [False] * V
    stack = []
    
    for i in range(V):
        if not visited[i]:
            dfs(i, adj, visited, stack)
    
    return stack[::-1]

# Kahn's Algorithm (BFS approach)
def topologicalSortBFS(V: int, adj: List[List[int]]) -> List[int]:
    indegree = [0] * V
    
    for i in range(V):
        for neighbor in adj[i]:
            indegree[neighbor] += 1
    
    q = deque()
    for i in range(V):
        if indegree[i] == 0:
            q.append(i)
    
    result = []
    while q:
        node = q.popleft()
        result.append(node)
        
        for neighbor in adj[node]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                q.append(neighbor)
    
    return result

def main():
    V = 6
    adj = [[] for _ in range(V)]
    
    adj[5].append(2)
    adj[5].append(0)
    adj[4].append(0)
    adj[4].append(1)
    adj[2].append(3)
    adj[3].append(1)
    
    result = topologicalSort(V, adj)
    
    print("DFS Topological Sort:", result)
    
    result = topologicalSortBFS(V, adj)
    
    print("BFS Topological Sort (Kahn's):", result)

if __name__ == "__main__":
    main()

"""
Time Complexity: O(V + E)
Space Complexity: O(V)
"""
