"""
Problem: Binary Search
Description: Search for a target value in a sorted array using binary search.

Approach: Divide search space in half repeatedly. Compare middle element with target.
"""

from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return -1

if __name__ == "__main__":
    sol = Solution()
    nums = [-1, 0, 3, 5, 9, 12]
    target = 9
    
    print(f"Index: {sol.search(nums, target)}")

"""
Time Complexity: O(log n) where n is the size of array
Space Complexity: O(1)
"""
