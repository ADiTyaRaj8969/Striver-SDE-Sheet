"""
Problem: Fractional Knapsack
Description: Given weights and values of items, maximize value in knapsack of capacity W. Can take fractions.

Approach: Calculate value/weight ratio for each item. Sort by ratio descending.
          Greedily take items with highest ratio.
"""

from typing import List

class Item:
    def __init__(self, value: int, weight: int):
        self.value = value
        self.weight = weight

def fractionalKnapsack(W: int, items: List[Item]) -> float:
    items.sort(key=lambda x: x.value / x.weight, reverse=True)
    
    maxValue = 0.0
    
    for item in items:
        if W >= item.weight:
            W -= item.weight
            maxValue += item.value
        else:
            maxValue += item.value * (W / item.weight)
            break
    
    return maxValue

def main():
    items = [Item(60, 10), Item(100, 20), Item(120, 30)]
    W = 50
    
    print(f"Maximum value: {fractionalKnapsack(W, items)}")
    # Output: 240.0

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n)
Space Complexity: O(1)
"""
