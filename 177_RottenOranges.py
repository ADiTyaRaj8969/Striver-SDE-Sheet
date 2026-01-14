"""
Problem: Rotten Oranges
Description: Find minimum time required to rot all oranges. Fresh orange rots if adjacent to rotten orange.

Approach: BFS from all initially rotten oranges. Track time level-wise.
"""

from typing import List
from collections import deque

def orangesRotting(grid: List[List[int]]) -> int:
    rows, cols = len(grid), len(grid[0])
    queue = deque()
    fresh = 0
    
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 2:
                queue.append((i, j))
            elif grid[i][j] == 1:
                fresh += 1
    
    if fresh == 0:
        return 0
    
    time = 0
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    while queue:
        size = len(queue)
        rotted = False
        
        for _ in range(size):
            x, y = queue.popleft()
            
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                
                if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] == 1:
                    grid[nx][ny] = 2
                    queue.append((nx, ny))
                    fresh -= 1
                    rotted = True
        
        if rotted:
            time += 1
    
    return time if fresh == 0 else -1

def main():
    grid = [
        [2, 1, 1],
        [1, 1, 0],
        [0, 1, 1]
    ]
    
    print(f"Time to rot all oranges: {orangesRotting(grid)}")
    # Output: 4

if __name__ == "__main__":
    main()

"""
Time Complexity: O(rows * cols)
Space Complexity: O(rows * cols)
"""
