"""
Problem: Kadane's Algorithm (Maximum Subarray Sum)
Description: Find the contiguous subarray with the largest sum.

Approach: Use Kadane's algorithm - maintain current sum and maximum sum.
          If current sum becomes negative, reset it to 0.
"""

from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = nums[0]
        current_sum = nums[0]
        
        for i in range(1, len(nums)):
            current_sum = max(nums[i], current_sum + nums[i])
            max_sum = max(max_sum, current_sum)
        
        return max_sum

if __name__ == "__main__":
    sol = Solution()
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(f"Maximum Subarray Sum: {sol.maxSubArray(nums)}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
"""
