"""
Problem: Minimum Coins (Coin Change - Greedy)
Description: Find the minimum number of coins to make a given amount of change.
             For standard denominations, greedy works.

Approach: Start with largest denomination, use as many as possible.
          Move to next smaller denomination.
"""

from typing import List

class Solution:
    def minCoins(self, coins: List[int], amount: int) -> int:
        coins.sort(reverse=True)
        
        count = 0
        
        for coin in coins:
            if amount == 0:
                break
            
            num_coins = amount // coin
            count += num_coins
            amount -= num_coins * coin
        
        return count if amount == 0 else -1

if __name__ == "__main__":
    sol = Solution()
    coins = [1, 2, 5, 10, 20, 50, 100, 500, 1000]
    amount = 93
    
    print(f"Minimum Coins: {sol.minCoins(coins, amount)}")

"""
Time Complexity: O(n) where n is number of coin denominations
Space Complexity: O(1)
Note: Greedy works for standard denominations only
"""
