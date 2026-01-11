"""
Problem: Stock Buy and Sell (Best Time to Buy and Sell Stock)
Description: Find the maximum profit from buying and selling a stock once.
             You must buy before you sell.

Approach: Track minimum price seen so far and calculate maximum profit at each step.
"""

from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float('inf')
        max_profit = 0
        
        for price in prices:
            min_price = min(min_price, price)
            max_profit = max(max_profit, price - min_price)
        
        return max_profit

if __name__ == "__main__":
    sol = Solution()
    prices = [7, 1, 5, 3, 6, 4]
    print(f"Maximum Profit: {sol.maxProfit(prices)}")

"""
Time Complexity: O(n) where n is the number of days
Space Complexity: O(1)
"""
