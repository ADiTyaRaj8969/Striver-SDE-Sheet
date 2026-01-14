"""
Problem: Rod Cutting
Description: Given a rod of length n and prices for different lengths,
             determine maximum value obtainable by cutting the rod.

Approach: DP - dp[i] = max value obtainable for rod of length i.
          For each length i, try all cuts and take maximum.
"""

from typing import List, Tuple

def rodCutting(prices: List[int], n: int) -> int:
    dp = [0] * (n + 1)
    
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            dp[i] = max(dp[i], prices[j-1] + dp[i-j])
    
    return dp[n]

# With cut tracking
def rodCuttingWithCuts(prices: List[int], n: int) -> Tuple[int, List[int]]:
    dp = [0] * (n + 1)
    cuts = [0] * (n + 1)
    
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            if prices[j-1] + dp[i-j] > dp[i]:
                dp[i] = prices[j-1] + dp[i-j]
                cuts[i] = j
    
    # Reconstruct cuts
    result = []
    length = n
    while length > 0:
        result.append(cuts[length])
        length -= cuts[length]
    
    return dp[n], result

def main():
    prices = [1, 5, 8, 9, 10, 17, 17, 20]
    n = 8
    
    print("Maximum value:", rodCutting(prices, n))  # Output: 22
    
    maxVal, cuts = rodCuttingWithCuts(prices, n)
    print("Maximum value:", maxVal)
    print("Cuts:", cuts)

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n^2)
Space Complexity: O(n)
"""
