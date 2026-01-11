"""
Problem: Fractional Knapsack
Description: Maximize the value of items in a knapsack with fractional weights allowed.

Approach: Calculate value/weight ratio for each item. Sort by ratio (descending).
          Greedily pick items with highest ratio first.
"""

from typing import List

class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight

class Solution:
    def fractionalKnapsack(self, W: int, items: List[Item], n: int) -> float:
        # Sort by value/weight ratio in descending order
        items.sort(key=lambda x: x.value / x.weight, reverse=True)
        
        total_value = 0.0
        current_weight = 0
        
        for item in items:
            if current_weight + item.weight <= W:
                # Take full item
                current_weight += item.weight
                total_value += item.value
            else:
                # Take fraction of item
                remaining = W - current_weight
                total_value += item.value * (remaining / item.weight)
                break
        
        return total_value

if __name__ == "__main__":
    sol = Solution()
    items = [Item(60, 10), Item(100, 20), Item(120, 30)]
    n = 3
    W = 50
    
    print(f"Maximum Value: {sol.fractionalKnapsack(W, items, n)}")

"""
Time Complexity: O(n log n) due to sorting
Space Complexity: O(1)
"""
