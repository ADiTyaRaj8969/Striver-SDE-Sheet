/*
Problem: Grid Unique Paths
Description: Find the number of unique paths from top-left to bottom-right of a grid.
             You can only move right or down.

Approach: Use combinatorics: C(m+n-2, m-1) = (m+n-2)! / ((m-1)! * (n-1)!)
          Or use dynamic programming.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Using combinatorics approach
        int N = m + n - 2;  // Total moves
        int r = m - 1;      // Down moves
        
        double result = 1;
        
        for (int i = 1; i <= r; i++) {
            result = result * (N - r + i) / i;
        }
        
        return (int)result;
    }
    
    // Alternative DP approach
    int uniquePathsDP(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    int m = 3, n = 7;
    cout << "Unique Paths: " << sol.uniquePaths(m, n) << endl;
    
    return 0;
}

/*
Time Complexity: O(m) or O(m*n) for DP approach
Space Complexity: O(1) or O(m*n) for DP approach
*/
