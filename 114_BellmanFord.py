"""
Problem: Bellman-Ford Algorithm
Description: Find shortest paths from source to all vertices in weighted graph.
             Can handle negative edge weights and detect negative cycles.

Approach: Relax all edges V-1 times. If we can still relax after V-1 iterations,
          there's a negative cycle.
"""

from typing import List, Tuple

def bellmanFord(V: int, edges: List[Tuple[int, int, int]], src: int) -> List[int]:
    dist = [float('inf')] * V
    dist[src] = 0
    
    # Relax all edges V-1 times
    for _ in range(V - 1):
        for src_node, dest, weight in edges:
            if dist[src_node] != float('inf') and dist[src_node] + weight < dist[dest]:
                dist[dest] = dist[src_node] + weight
    
    # Check for negative cycle
    for src_node, dest, weight in edges:
        if dist[src_node] != float('inf') and dist[src_node] + weight < dist[dest]:
            print("Graph contains negative cycle")
            return []
    
    return dist

def main():
    V = 5
    edges = [
        (0, 1, -1),
        (0, 2, 4),
        (1, 2, 3),
        (1, 3, 2),
        (1, 4, 2),
        (3, 2, 5),
        (3, 1, 1),
        (4, 3, -3)
    ]
    
    distances = bellmanFord(V, edges, 0)
    
    if distances:
        print("Shortest distances from source 0:")
        for i in range(V):
            if distances[i] == float('inf'):
                print(f"{i}: INF")
            else:
                print(f"{i}: {distances[i]}")

if __name__ == "__main__":
    main()

"""
Time Complexity: O(V * E)
Space Complexity: O(V)
"""
