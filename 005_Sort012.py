"""
Problem: Sort 0s, 1s, 2s (Dutch National Flag Algorithm)
Description: Sort an array containing only 0s, 1s, and 2s without using sorting algorithms.

Approach: Use three pointers - low, mid, high. 
          Swap elements to place 0s at beginning, 2s at end, and 1s in middle.
"""

from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        low, mid, high = 0, 0, len(nums) - 1
        
        while mid <= high:
            if nums[mid] == 0:
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:  # nums[mid] == 2
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1

if __name__ == "__main__":
    sol = Solution()
    nums = [2, 0, 2, 1, 1, 0]
    sol.sortColors(nums)
    print(nums)

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1) - in-place sorting
"""
