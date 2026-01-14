"""
Problem: Minimum Spanning Tree - Prim's Algorithm
Description: Find a minimum spanning tree (MST) for a weighted undirected graph.
             MST connects all vertices with minimum total edge weight.

Approach: Start from any vertex, greedily add minimum weight edge that connects
          a vertex in MST to a vertex outside MST.
"""

from typing import List, Tuple
import heapq

def primMST(V: int, adj: List[List[Tuple[int, int]]]) -> int:
    inMST = [False] * V
    pq = [(0, 0)]  # (weight, vertex)
    mstWeight = 0
    
    while pq:
        weight, u = heapq.heappop(pq)
        
        if inMST[u]:
            continue
        
        inMST[u] = True
        mstWeight += weight
        
        for v, w in adj[u]:
            if not inMST[v]:
                heapq.heappush(pq, (w, v))
    
    return mstWeight

def main():
    V = 5
    adj = [[] for _ in range(V)]
    
    adj[0].append((1, 2))
    adj[1].append((0, 2))
    adj[0].append((3, 6))
    adj[3].append((0, 6))
    adj[1].append((2, 3))
    adj[2].append((1, 3))
    adj[1].append((3, 8))
    adj[3].append((1, 8))
    adj[1].append((4, 5))
    adj[4].append((1, 5))
    adj[2].append((4, 7))
    adj[4].append((2, 7))
    
    mstWeight = primMST(V, adj)
    
    print(f"Weight of MST: {mstWeight}")

if __name__ == "__main__":
    main()

"""
Time Complexity: O((V + E) log V)
Space Complexity: O(V)
"""
