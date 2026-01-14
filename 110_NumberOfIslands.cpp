/*
Problem: Number of Islands
Description: Count the number of islands in a 2D grid. An island is surrounded by
             water and is formed by connecting adjacent lands horizontally or vertically.

Approach: Use DFS or BFS to mark connected components. Each unvisited land cell
          that we start DFS from represents a new island.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
        return;
    
    grid[i][j] = '0';  // Mark as visited
    
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    cout << "Number of Islands: " << numIslands(grid) << endl;  // Output: 3
    
    return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n) for recursion stack in worst case
*/
