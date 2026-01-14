"""
Problem: Strongly Connected Components (Kosaraju's Algorithm)
Description: Find all strongly connected components in a directed graph.
             A strongly connected component is a maximal set of vertices where
             every vertex is reachable from every other vertex.

Approach: Kosaraju's Algorithm
          1. Do DFS and store nodes in stack by finish time
          2. Transpose the graph
          3. Do DFS on transposed graph in order of stack
"""

from typing import List

def dfs1(node: int, adj: List[List[int]], visited: List[bool], stack: List[int]):
    visited[node] = True
    
    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs1(neighbor, adj, visited, stack)
    
    stack.append(node)

def dfs2(node: int, transpose: List[List[int]], visited: List[bool], component: List[int]):
    visited[node] = True
    component.append(node)
    
    for neighbor in transpose[node]:
        if not visited[neighbor]:
            dfs2(neighbor, transpose, visited, component)

def findSCCs(V: int, adj: List[List[int]]) -> List[List[int]]:
    # Step 1: Do DFS and fill stack
    visited = [False] * V
    stack = []
    
    for i in range(V):
        if not visited[i]:
            dfs1(i, adj, visited, stack)
    
    # Step 2: Create transpose graph
    transpose = [[] for _ in range(V)]
    for i in range(V):
        for neighbor in adj[i]:
            transpose[neighbor].append(i)
    
    # Step 3: Do DFS on transpose in order of stack
    visited = [False] * V
    sccs = []
    
    while stack:
        node = stack.pop()
        
        if not visited[node]:
            component = []
            dfs2(node, transpose, visited, component)
            sccs.append(component)
    
    return sccs

def main():
    V = 5
    adj = [[] for _ in range(V)]
    
    adj[0].append(1)
    adj[1].append(2)
    adj[2].append(0)
    adj[1].append(3)
    adj[3].append(4)
    
    sccs = findSCCs(V, adj)
    
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)

if __name__ == "__main__":
    main()

"""
Time Complexity: O(V + E)
Space Complexity: O(V)
"""
