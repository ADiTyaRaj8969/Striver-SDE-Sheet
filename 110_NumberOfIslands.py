"""
Problem: Number of Islands
Description: Count the number of islands in a 2D grid. An island is surrounded by
             water and is formed by connecting adjacent lands horizontally or vertically.

Approach: Use DFS or BFS to mark connected components. Each unvisited land cell
          that we start DFS from represents a new island.
"""

from typing import List

def dfs(grid: List[List[str]], i: int, j: int):
    m, n = len(grid), len(grid[0])
    
    if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == '0':
        return
    
    grid[i][j] = '0'  # Mark as visited
    
    dfs(grid, i + 1, j)
    dfs(grid, i - 1, j)
    dfs(grid, i, j + 1)
    dfs(grid, i, j - 1)

def numIslands(grid: List[List[str]]) -> int:
    if not grid:
        return 0
    
    m, n = len(grid), len(grid[0])
    count = 0
    
    for i in range(m):
        for j in range(n):
            if grid[i][j] == '1':
                count += 1
                dfs(grid, i, j)
    
    return count

def main():
    grid = [
        ['1', '1', '0', '0', '0'],
        ['1', '1', '0', '0', '0'],
        ['0', '0', '1', '0', '0'],
        ['0', '0', '0', '1', '1']
    ]
    
    print("Number of Islands:", numIslands(grid))  # Output: 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(m * n)
Space Complexity: O(m * n) for recursion stack in worst case
"""
