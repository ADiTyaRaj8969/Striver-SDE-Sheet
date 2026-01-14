"""
Problem: Minimum Coins
Description: Find minimum number of coins needed to make a given amount using coins of given denominations.

Approach: Use greedy approach (works for canonical coin systems). Sort denominations descending and pick largest coins.
"""

from typing import List

def minCoins(coins: List[int], amount: int) -> List[int]:
    coins.sort(reverse=True)
    
    result = []
    
    for coin in coins:
        while amount >= coin:
            amount -= coin
            result.append(coin)
    
    if amount > 0:
        return []  # Not possible
    
    return result

def main():
    coins = [1, 2, 5, 10, 20, 50, 100, 500, 1000]
    amount = 93
    
    result = minCoins(coins, amount)
    
    print(f"Minimum coins needed: {len(result)}")
    print(f"Coins: {result}")
    # Output: 5 coins [50, 20, 20, 2, 1]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n + amount)
Space Complexity: O(result size)
"""
