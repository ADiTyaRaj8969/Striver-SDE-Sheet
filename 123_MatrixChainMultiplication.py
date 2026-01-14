"""
Problem: Matrix Chain Multiplication
Description: Find minimum number of scalar multiplications needed to multiply
             a chain of matrices.

Approach: DP - dp[i][j] = min operations to multiply matrices from i to j.
          Try all possible split points k and take minimum.
"""

from typing import List

def matrixChainMultiplication(dims: List[int]) -> int:
    n = len(dims) - 1  # Number of matrices
    dp = [[0] * n for _ in range(n)]
    
    # len is chain length
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = float('inf')
            
            # Try all split points
            for k in range(i, j):
                cost = dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1]
                dp[i][j] = min(dp[i][j], cost)
    
    return dp[0][n-1]

# Recursive with memoization
def mcmHelper(dims: List[int], i: int, j: int, memo: List[List[int]]) -> int:
    if i == j:
        return 0
    
    if memo[i][j] != -1:
        return memo[i][j]
    
    minCost = float('inf')
    
    for k in range(i, j):
        cost = (mcmHelper(dims, i, k, memo) + 
                mcmHelper(dims, k+1, j, memo) + 
                dims[i] * dims[k+1] * dims[j+1])
        minCost = min(minCost, cost)
    
    memo[i][j] = minCost
    return minCost

def matrixChainMultiplicationMemo(dims: List[int]) -> int:
    n = len(dims) - 1
    memo = [[-1] * n for _ in range(n)]
    return mcmHelper(dims, 0, n-1, memo)

def main():
    dims = [40, 20, 30, 10, 30]
    # Matrices: A1(40x20), A2(20x30), A3(30x10), A4(10x30)
    
    print("Minimum multiplications:", matrixChainMultiplication(dims))  # Output: 26000
    print("Minimum multiplications (Memo):", matrixChainMultiplicationMemo(dims))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n^3)
Space Complexity: O(n^2)
"""
