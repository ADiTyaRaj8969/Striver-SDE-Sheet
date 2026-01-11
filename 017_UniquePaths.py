"""
Problem: Grid Unique Paths
Description: Find the number of unique paths from top-left to bottom-right of a grid.
             You can only move right or down.

Approach: Use combinatorics: C(m+n-2, m-1) = (m+n-2)! / ((m-1)! * (n-1)!)
          Or use dynamic programming.
"""

from typing import List

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # Using combinatorics approach
        N = m + n - 2  # Total moves
        r = m - 1      # Down moves
        
        result = 1
        
        for i in range(1, r + 1):
            result = result * (N - r + i) // i
        
        return result
    
    # Alternative DP approach
    def uniquePathsDP(self, m: int, n: int) -> int:
        dp = [[1] * n for _ in range(m)]
        
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
        return dp[m-1][n-1]

if __name__ == "__main__":
    sol = Solution()
    m, n = 3, 7
    print(f"Unique Paths: {sol.uniquePaths(m, n)}")

"""
Time Complexity: O(m) or O(m*n) for DP approach
Space Complexity: O(1) or O(m*n) for DP approach
"""
