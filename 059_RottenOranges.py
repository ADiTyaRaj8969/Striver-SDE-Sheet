"""
Problem: Rotten Oranges
Description: Given a grid with fresh and rotten oranges, find minimum time
             for all oranges to rot. Rotten orange rots adjacent fresh oranges.

Approach: Multi-source BFS from all initially rotten oranges simultaneously.
"""

from typing import List
from collections import deque

def orangesRotting(grid: List[List[int]]) -> int:
    m, n = len(grid), len(grid[0])
    queue = deque()
    fresh = 0
    
    # Count fresh oranges and add rotten ones to queue
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 2:
                queue.append((i, j))
            elif grid[i][j] == 1:
                fresh += 1
    
    if fresh == 0:
        return 0
    
    minutes = 0
    dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
    while queue:
        size = len(queue)
        rotted = False
        
        for _ in range(size):
            r, c = queue.popleft()
            
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    queue.append((nr, nc))
                    fresh -= 1
                    rotted = True
        
        if rotted:
            minutes += 1
    
    return minutes if fresh == 0 else -1

def main():
    grid1 = [[2, 1, 1], [1, 1, 0], [0, 1, 1]]
    print(orangesRotting(grid1))  # Output: 4
    
    grid2 = [[2, 1, 1], [0, 1, 1], [1, 0, 1]]
    print(orangesRotting(grid2))  # Output: -1

if __name__ == "__main__":
    main()

"""
Time Complexity: O(m * n)
Space Complexity: O(m * n)
"""
