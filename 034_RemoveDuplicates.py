"""
Problem: Remove Duplicates from Sorted Array
Description: Remove duplicates from a sorted array in-place and return new length.

Approach: Use two pointers - one for unique position, one for scanning.
"""

from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        unique_pos = 0
        
        for i in range(1, len(nums)):
            if nums[i] != nums[unique_pos]:
                unique_pos += 1
                nums[unique_pos] = nums[i]
        
        return unique_pos + 1

if __name__ == "__main__":
    sol = Solution()
    nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    new_length = sol.removeDuplicates(nums)
    
    print(f"New Length: {new_length}")
    print(f"Array: {nums[:new_length]}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
"""
