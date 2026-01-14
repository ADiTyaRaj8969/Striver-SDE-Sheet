"""
Problem: 0-1 Knapsack
Description: Given weights and values of n items, put items in a knapsack of
             capacity W to get maximum total value. Each item can be taken once.

Approach: DP - dp[i][w] = max value using first i items with capacity w.
          Choice: Include item i or exclude it.
"""

from typing import List

def knapsack(weights: List[int], values: List[int], W: int) -> int:
    n = len(weights)
    dp = [[0] * (W + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for w in range(W + 1):
            # Don't include item i-1
            dp[i][w] = dp[i-1][w]
            
            # Include item i-1 if possible
            if weights[i-1] <= w:
                dp[i][w] = max(dp[i][w], values[i-1] + dp[i-1][w - weights[i-1]])
    
    return dp[n][W]

# Space optimized version
def knapsackOptimized(weights: List[int], values: List[int], W: int) -> int:
    n = len(weights)
    dp = [0] * (W + 1)
    
    for i in range(n):
        for w in range(W, weights[i] - 1, -1):
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]])
    
    return dp[W]

def main():
    weights = [1, 3, 4, 5]
    values = [1, 4, 5, 7]
    W = 7
    
    print("Maximum value:", knapsack(weights, values, W))  # Output: 9
    print("Maximum value (optimized):", knapsackOptimized(weights, values, W))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n * W)
Space Complexity: O(n * W) or O(W) for optimized version
"""
