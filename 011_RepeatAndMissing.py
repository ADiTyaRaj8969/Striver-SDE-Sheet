"""
Problem: Repeat and Missing Number
Description: Find the repeating and the missing number in an array from 1 to N.

Approach: Use mathematical formulas:
          Let x = repeating, y = missing
          S - Sn = x - y (sum difference)
          S2 - S2n = x^2 - y^2 (square sum difference)
          From these, derive x and y
"""

from typing import List

class Solution:
    def findTwoElement(self, arr: List[int]) -> List[int]:
        n = len(arr)
        S = sum(arr)
        S2 = sum(x * x for x in arr)
        
        Sn = (n * (n + 1)) // 2
        S2n = (n * (n + 1) * (2 * n + 1)) // 6
        
        diff = S - Sn           # x - y
        sum_val = (S2 - S2n) // diff  # x + y
        
        repeating = (diff + sum_val) // 2
        missing = sum_val - repeating
        
        return [repeating, missing]

if __name__ == "__main__":
    sol = Solution()
    arr = [4, 3, 6, 2, 1, 1]
    result = sol.findTwoElement(arr)
    print(f"Repeating: {result[0]}, Missing: {result[1]}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
"""
