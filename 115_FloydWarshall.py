"""
Problem: Floyd-Warshall Algorithm
Description: Find shortest paths between all pairs of vertices in a weighted graph.
             Can handle negative edge weights but not negative cycles.

Approach: Dynamic Programming. For each intermediate vertex k, check if path
          through k is shorter than direct path.
"""

from typing import List

def floydWarshall(graph: List[List[int]]):
    V = len(graph)
    dist = [row[:] for row in graph]  # Copy the graph
    
    # Consider all vertices as intermediate
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    
    # Print the solution
    print("Shortest distances between all pairs:")
    for i in range(V):
        for j in range(V):
            if dist[i][j] == float('inf'):
                print("INF", end=" ")
            else:
                print(dist[i][j], end=" ")
        print()

def main():
    V = 4
    INF = float('inf')
    graph = [[INF] * V for _ in range(V)]
    
    # Distance from a vertex to itself is 0
    for i in range(V):
        graph[i][i] = 0
    
    graph[0][1] = 5
    graph[0][3] = 10
    graph[1][2] = 3
    graph[2][3] = 1
    
    floydWarshall(graph)

if __name__ == "__main__":
    main()

"""
Time Complexity: O(V^3)
Space Complexity: O(V^2)
"""
