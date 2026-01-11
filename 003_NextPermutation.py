"""
Problem: Next Permutation
Description: Find the next lexicographically greater permutation of a given sequence.
             If no such permutation exists, rearrange to the lowest possible order.

Approach: 1. Find the largest index i such that nums[i] < nums[i+1]
          2. Find the largest index j > i such that nums[i] < nums[j]
          3. Swap nums[i] and nums[j]
          4. Reverse the subarray from i+1 to end
"""

from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        i = n - 2
        
        # Find first decreasing element from right
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        
        if i >= 0:
            # Find element just larger than nums[i]
            j = n - 1
            while j >= 0 and nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        
        # Reverse the suffix
        nums[i + 1:] = reversed(nums[i + 1:])

if __name__ == "__main__":
    sol = Solution()
    nums = [1, 2, 3]
    sol.nextPermutation(nums)
    print(nums)

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1) - in-place modification
"""
