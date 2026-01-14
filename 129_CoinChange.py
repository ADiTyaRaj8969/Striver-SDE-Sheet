"""
Problem: Coin Change
Description: Find minimum number of coins needed to make amount.
             You have infinite supply of each coin denomination.

Approach: DP - dp[i] = min coins needed to make amount i.
          For each amount, try all coin denominations.
"""

from typing import List

def coinChange(coins: List[int], amount: int) -> int:
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    
    for i in range(1, amount + 1):
        for coin in coins:
            if coin <= i and dp[i - coin] != float('inf'):
                dp[i] = min(dp[i], dp[i - coin] + 1)
    
    return dp[amount] if dp[amount] != float('inf') else -1

# Coin Change II: Count number of ways to make amount
def coinChangeWays(coins: List[int], amount: int) -> int:
    dp = [0] * (amount + 1)
    dp[0] = 1
    
    for coin in coins:
        for i in range(coin, amount + 1):
            dp[i] += dp[i - coin]
    
    return dp[amount]

def main():
    coins1 = [1, 2, 5]
    amount1 = 11
    print("Minimum coins:", coinChange(coins1, amount1))  # Output: 3
    print("Number of ways:", coinChangeWays(coins1, amount1))
    
    coins2 = [2]
    amount2 = 3
    print("Minimum coins:", coinChange(coins2, amount2))  # Output: -1

if __name__ == "__main__":
    main()

"""
Time Complexity: O(amount * n)
Space Complexity: O(amount)
"""
