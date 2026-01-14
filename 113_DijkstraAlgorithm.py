"""
Problem: Dijkstra's Algorithm
Description: Find shortest paths from source vertex to all other vertices in a
             weighted graph with non-negative edge weights.

Approach: Use priority queue (min-heap). Greedily pick the unvisited vertex with
          smallest distance, update distances of its neighbors.
"""

from typing import List, Tuple
import heapq

def dijkstra(V: int, adj: List[List[Tuple[int, int]]], src: int) -> List[int]:
    dist = [float('inf')] * V
    pq = [(0, src)]
    dist[src] = 0
    
    while pq:
        d, u = heapq.heappop(pq)
        
        if d > dist[u]:
            continue
        
        for v, weight in adj[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                heapq.heappush(pq, (dist[v], v))
    
    return dist

def main():
    V = 5
    adj = [[] for _ in range(V)]
    
    adj[0].append((1, 2))
    adj[0].append((2, 4))
    adj[1].append((2, 1))
    adj[1].append((3, 7))
    adj[2].append((4, 3))
    adj[3].append((4, 1))
    
    distances = dijkstra(V, adj, 0)
    
    print("Shortest distances from source 0:")
    for i in range(V):
        if distances[i] == float('inf'):
            print(f"{i}: INF")
        else:
            print(f"{i}: {distances[i]}")

if __name__ == "__main__":
    main()

"""
Time Complexity: O((V + E) log V)
Space Complexity: O(V)
"""
