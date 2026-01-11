"""
Problem: Largest Subarray with 0 Sum
Description: Find the length of the largest subarray with a sum of 0.

Approach: Use prefix sum with hash map. If same prefix sum appears twice,
          the subarray between them has sum 0.
"""

from typing import List

class Solution:
    def maxLen(self, arr: List[int]) -> int:
        prefix_sum_map = {}
        sum_val = 0
        max_length = 0
        
        for i, num in enumerate(arr):
            sum_val += num
            
            if sum_val == 0:
                max_length = i + 1
            
            if sum_val in prefix_sum_map:
                max_length = max(max_length, i - prefix_sum_map[sum_val])
            else:
                prefix_sum_map[sum_val] = i
        
        return max_length

if __name__ == "__main__":
    sol = Solution()
    arr = [15, -2, 2, -8, 1, 7, 10, 23]
    print(f"Largest Subarray with 0 Sum: {sol.maxLen(arr)}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(n) for the hash map
"""
