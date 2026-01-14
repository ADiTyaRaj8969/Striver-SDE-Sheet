/*
Problem: Rotten Oranges
Description: Find minimum time required to rot all oranges. Fresh orange rots if adjacent to rotten orange.

Approach: BFS from all initially rotten oranges. Track time level-wise.
*/

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    
    if (fresh == 0) return 0;
    
    int time = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        int size = q.size();
        bool rotted = false;
        
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                    rotted = true;
                }
            }
        }
        
        if (rotted) time++;
    }
    
    return fresh == 0 ? time : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    
    cout << "Time to rot all oranges: " << orangesRotting(grid) << endl;
    // Output: 4
    
    return 0;
}

/*
Time Complexity: O(rows * cols)
Space Complexity: O(rows * cols)
*/
