"""
Problem: Find Duplicate in Array (Floyd's Cycle Detection)
Description: Find the one duplicate number in an array of N+1 integers from 1 to N.

Approach: Use Floyd's cycle detection algorithm (tortoise and hare).
          Treat array values as pointers to next index.
"""

from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # Phase 1: Find intersection point in the cycle
        slow = nums[0]
        fast = nums[0]
        
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        
        # Phase 2: Find the entrance to the cycle
        slow = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
        
        return slow

if __name__ == "__main__":
    sol = Solution()
    nums = [1, 3, 4, 2, 2]
    print(f"Duplicate Number: {sol.findDuplicate(nums)}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
"""
