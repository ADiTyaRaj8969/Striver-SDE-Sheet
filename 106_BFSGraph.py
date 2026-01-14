"""
Problem: BFS of Graph
Description: Perform Breadth First Search traversal of a graph.

Approach: Use queue for level-order traversal, mark visited nodes.
"""

from typing import List
from collections import deque

def bfsOfGraph(V: int, adj: List[List[int]]) -> List[int]:
    visited = [False] * V
    result = []
    queue = deque([0])
    visited[0] = True
    
    while queue:
        node = queue.popleft()
        result.append(node)
        
        for neighbor in adj[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)
    
    return result

def main():
    V = 5
    adj = [[] for _ in range(V)]
    
    adj[0].append(1)
    adj[0].append(2)
    adj[1].append(3)
    adj[2].append(4)
    
    result = bfsOfGraph(V, adj)
    print(result)

if __name__ == "__main__":
    main()

"""
Time Complexity: O(V + E)
Space Complexity: O(V)
"""
