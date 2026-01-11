"""
Problem: Subset II (Unique Subsets)
Description: Find all unique subsets from an array that may contain duplicates.

Approach: Sort array, use backtracking and skip duplicates at same recursion level.
"""

from typing import List

class Solution:
    def findSubsets(self, index: int, nums: List[int], current: List[int], 
                    result: List[List[int]]):
        result.append(current[:])
        
        for i in range(index, len(nums)):
            # Skip duplicates
            if i > index and nums[i] == nums[i - 1]:
                continue
            
            current.append(nums[i])
            self.findSubsets(i + 1, nums, current, result)
            current.pop()
    
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        current = []
        
        nums.sort()
        self.findSubsets(0, nums, current, result)
        
        return result

if __name__ == "__main__":
    sol = Solution()
    nums = [1, 2, 2]
    result = sol.subsetsWithDup(nums)
    
    print("Unique Subsets:")
    for subset in result:
        print(subset)

"""
Time Complexity: O(2^n) where n is the size of array
Space Complexity: O(2^n) for storing all subsets
"""
