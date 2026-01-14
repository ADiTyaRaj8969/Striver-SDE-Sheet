"""
Problem: Minimum Spanning Tree - Kruskal's Algorithm
Description: Find a minimum spanning tree (MST) using union-find.
             Sort edges by weight and add edge if it doesn't form cycle.

Approach: Sort all edges by weight. Use Union-Find to check cycles.
          Add edge to MST if it connects two different components.
"""

from typing import List, Tuple

class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n
    
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def unite(self, x: int, y: int) -> bool:
        px = self.find(x)
        py = self.find(y)
        
        if px == py:
            return False
        
        if self.rank[px] < self.rank[py]:
            self.parent[px] = py
        elif self.rank[px] > self.rank[py]:
            self.parent[py] = px
        else:
            self.parent[py] = px
            self.rank[px] += 1
        
        return True

def kruskalMST(V: int, edges: List[Tuple[int, int, int]]) -> int:
    edges.sort(key=lambda x: x[2])  # Sort by weight
    
    uf = UnionFind(V)
    mstWeight = 0
    edgeCount = 0
    
    for u, v, weight in edges:
        if uf.unite(u, v):
            mstWeight += weight
            edgeCount += 1
            
            if edgeCount == V - 1:
                break
    
    return mstWeight

def main():
    V = 5
    edges = [
        (0, 1, 2), (0, 3, 6), (1, 2, 3),
        (1, 3, 8), (1, 4, 5), (2, 4, 7)
    ]
    
    mstWeight = kruskalMST(V, edges)
    
    print(f"Weight of MST: {mstWeight}")

if __name__ == "__main__":
    main()

"""
Time Complexity: O(E log E)
Space Complexity: O(V)
"""
