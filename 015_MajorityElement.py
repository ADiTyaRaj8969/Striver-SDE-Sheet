"""
Problem: Majority Element (>n/2 times)
Description: Find the element that appears more than n/2 times in the array.

Approach: Use Moore's Voting Algorithm - maintain a candidate and count.
          The majority element will always win the voting.
"""

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = 0
        count = 0
        
        # Find candidate
        for num in nums:
            if count == 0:
                candidate = num
            count += 1 if num == candidate else -1
        
        return candidate

if __name__ == "__main__":
    sol = Solution()
    nums = [2, 2, 1, 1, 1, 2, 2]
    print(f"Majority Element: {sol.majorityElement(nums)}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
"""
