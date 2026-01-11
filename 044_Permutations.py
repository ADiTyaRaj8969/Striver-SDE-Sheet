"""
Problem: Permutations
Description: Find all possible permutations of a string or array.

Approach: Use backtracking with swapping. Swap each element with current position
          and recurse for remaining positions.
"""

from typing import List

class Solution:
    def generatePermutations(self, index: int, nums: List[int], result: List[List[int]]):
        if index == len(nums):
            result.append(nums[:])
            return
        
        for i in range(index, len(nums)):
            nums[index], nums[i] = nums[i], nums[index]
            self.generatePermutations(index + 1, nums, result)
            nums[index], nums[i] = nums[i], nums[index]  # backtrack
    
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        self.generatePermutations(0, nums, result)
        return result

if __name__ == "__main__":
    sol = Solution()
    nums = [1, 2, 3]
    result = sol.permute(nums)
    
    print("Permutations:")
    for perm in result:
        print(perm)

"""
Time Complexity: O(n! * n) where n is the size of array
Space Complexity: O(n) for recursion depth
"""
