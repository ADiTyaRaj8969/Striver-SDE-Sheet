"""
Problem: Two Sum
Description: Find two numbers in an array that add up to a target value.

Approach: Use hash map to store complement of each element.
          Check if current element exists in map.
"""

from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        
        for i, num in enumerate(nums):
            complement = target - num
            
            if complement in num_map:
                return [num_map[complement], i]
            
            num_map[num] = i
        
        return []

if __name__ == "__main__":
    sol = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    result = sol.twoSum(nums, target)
    print(f"Indices: {result}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(n) for the hash map
"""
