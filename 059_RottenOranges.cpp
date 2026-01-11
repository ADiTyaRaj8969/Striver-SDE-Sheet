/*
Problem: Rotten Oranges
Description: Given a grid with fresh and rotten oranges, find minimum time
             for all oranges to rot. Rotten orange rots adjacent fresh oranges.

Approach: Multi-source BFS from all initially rotten oranges simultaneously.
*/

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    
    // Count fresh oranges and add rotten ones to queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    
    if (fresh == 0) return 0;
    
    int minutes = 0;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    while (!q.empty()) {
        int size = q.size();
        bool rotted = false;
        
        for (int i = 0; i < size; i++) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;
                    rotted = true;
                }
            }
        }
        
        if (rotted) minutes++;
    }
    
    return fresh == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid1) << endl;  // Output: 4
    
    vector<vector<int>> grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << orangesRotting(grid2) << endl;  // Output: -1
    
    return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
