"""
Problem: Majority Element II (>n/3 times)
Description: Find all elements that appear more than n/3 times in the array.
             At most 2 elements can appear more than n/3 times.

Approach: Extended Moore's Voting Algorithm with 2 candidates.
          Verify candidates in a second pass.
"""

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        candidate1, candidate2 = 0, 0
        count1, count2 = 0, 0
        
        # Find two candidates
        for num in nums:
            if num == candidate1:
                count1 += 1
            elif num == candidate2:
                count2 += 1
            elif count1 == 0:
                candidate1 = num
                count1 = 1
            elif count2 == 0:
                candidate2 = num
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1
        
        # Verify candidates
        result = []
        count1 = count2 = 0
        
        for num in nums:
            if num == candidate1:
                count1 += 1
            elif num == candidate2:
                count2 += 1
        
        n = len(nums)
        if count1 > n // 3:
            result.append(candidate1)
        if count2 > n // 3:
            result.append(candidate2)
        
        return result

if __name__ == "__main__":
    sol = Solution()
    nums = [3, 2, 3]
    result = sol.majorityElement(nums)
    print(f"Majority Elements: {result}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
"""
