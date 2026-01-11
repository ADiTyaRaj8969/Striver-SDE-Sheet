"""
Problem: Max Consecutive Ones
Description: Find the maximum number of consecutive 1s in a binary array.

Approach: Use a counter to track consecutive ones, update max when 0 is encountered.
"""

from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_count = 0
        current_count = 0
        
        for num in nums:
            if num == 1:
                current_count += 1
                max_count = max(max_count, current_count)
            else:
                current_count = 0
        
        return max_count

if __name__ == "__main__":
    sol = Solution()
    nums = [1, 1, 0, 1, 1, 1]
    print(f"Max Consecutive Ones: {sol.findMaxConsecutiveOnes(nums)}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
"""
