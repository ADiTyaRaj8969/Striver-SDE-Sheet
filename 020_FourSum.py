"""
Problem: Four Sum
Description: Find all unique quadruplets in an array that sum up to a target value.

Approach: Sort array, use two pointers with nested loops.
          Skip duplicates to ensure unique quadruplets.
"""

from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        n = len(nums)
        
        if n < 4:
            return result
        
        nums.sort()
        
        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                
                left, right = j + 1, n - 1
                
                while left < right:
                    total = nums[i] + nums[j] + nums[left] + nums[right]
                    
                    if total == target:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        
                        left += 1
                        right -= 1
                    elif total < target:
                        left += 1
                    else:
                        right -= 1
        
        return result

if __name__ == "__main__":
    sol = Solution()
    nums = [1, 0, -1, 0, -2, 2]
    target = 0
    result = sol.fourSum(nums, target)
    print(result)

"""
Time Complexity: O(n^3) where n is the length of the array
Space Complexity: O(1) excluding the result array
"""
