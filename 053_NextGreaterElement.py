"""
Problem: Next Greater Element
Description: Find the next greater element for each element in an array.

Approach: Use stack. Traverse from right to left, maintain stack of potential
          next greater elements.
"""

from typing import List

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [-1] * n
        stack = []
        
        # Traverse from right to left
        for i in range(n - 1, -1, -1):
            # Pop smaller elements
            while stack and stack[-1] <= nums[i]:
                stack.pop()
            
            # Top of stack is next greater element
            if stack:
                result[i] = stack[-1]
            
            # Push current element
            stack.append(nums[i])
        
        return result

if __name__ == "__main__":
    sol = Solution()
    nums = [4, 5, 2, 10, 8]
    result = sol.nextGreaterElements(nums)
    
    print(f"Next Greater Elements: {result}")

"""
Time Complexity: O(n) where n is the size of array
Space Complexity: O(n) for the stack
"""
