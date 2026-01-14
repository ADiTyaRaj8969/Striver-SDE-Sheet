"""
Problem: DFS of Graph
Description: Perform Depth First Search traversal of a graph.

Approach: Use recursion to visit nodes, mark as visited to avoid cycles.
"""

from typing import List

def dfsHelper(node: int, adj: List[List[int]], visited: List[bool], result: List[int]):
    visited[node] = True
    result.append(node)
    
    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfsHelper(neighbor, adj, visited, result)

def dfsOfGraph(V: int, adj: List[List[int]]) -> List[int]:
    visited = [False] * V
    result = []
    
    dfsHelper(0, adj, visited, result)
    
    return result

def main():
    V = 5
    adj = [[] for _ in range(V)]
    
    adj[0].append(1)
    adj[0].append(2)
    adj[1].append(3)
    adj[2].append(4)
    
    result = dfsOfGraph(V, adj)
    print(result)

if __name__ == "__main__":
    main()

"""
Time Complexity: O(V + E)
Space Complexity: O(V)
"""
