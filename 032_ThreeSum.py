"""
Problem: Three Sum
Description: Find all unique triplets in an array that sum to zero.

Approach: Sort array, fix one element and use two pointers for remaining two.
          Skip duplicates to ensure unique triplets.
"""

from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        n = len(nums)
        
        if n < 3:
            return result
        
        nums.sort()
        
        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            left, right = i + 1, n - 1
            target = -nums[i]
            
            while left < right:
                total = nums[left] + nums[right]
                
                if total == target:
                    result.append([nums[i], nums[left], nums[right]])
                    
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
    nums = [-1, 0, 1, 2, -1, -4]
    result = sol.threeSum(nums)
    print("Triplets:")
    for triplet in result:
        print(triplet)

"""
Time Complexity: O(n^2) where n is the length of the array
Space Complexity: O(1) excluding the result array
"""
