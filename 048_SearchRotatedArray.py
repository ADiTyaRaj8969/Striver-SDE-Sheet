"""
Problem: Search in Rotated Sorted Array
Description: Search for an element in a sorted array that has been rotated.

Approach: Modified binary search. One half is always sorted. Check which half
          is sorted and if target lies in that range.
"""

from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if nums[mid] == target:
                return mid
            
            # Left half is sorted
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            # Right half is sorted
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        
        return -1

if __name__ == "__main__":
    sol = Solution()
    nums = [4, 5, 6, 7, 0, 1, 2]
    target = 0
    
    print(f"Index: {sol.search(nums, target)}")

"""
Time Complexity: O(log n) where n is the size of array
Space Complexity: O(1)
"""
