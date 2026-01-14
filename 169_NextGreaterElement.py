"""
Problem: Next Greater Element
Description: For each element in array, find next greater element to its right.

Approach: Use stack. Traverse from right. Pop smaller elements. Top is next greater.
"""

from typing import List

def nextGreaterElement(nums: List[int]) -> List[int]:
    n = len(nums)
    result = [-1] * n
    stack = []
    
    for i in range(n - 1, -1, -1):
        while stack and stack[-1] <= nums[i]:
            stack.pop()
        
        if stack:
            result[i] = stack[-1]
        
        stack.append(nums[i])
    
    return result

def main():
    nums = [4, 5, 2, 10, 8]
    result = nextGreaterElement(nums)
    
    print(f"Next greater elements: {result}")
    # Output: [5, 10, 10, -1, -1]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
