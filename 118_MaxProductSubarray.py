"""
Problem: Maximum Product Subarray
Description: Find the contiguous subarray within an array which has the largest product.

Approach: Keep track of both max and min products ending at current position.
          Min can become max when multiplied by negative number.
"""

from typing import List

def maxProduct(nums: List[int]) -> int:
    if not nums:
        return 0
    
    maxProd = nums[0]
    minProd = nums[0]
    result = nums[0]
    
    for i in range(1, len(nums)):
        if nums[i] < 0:
            maxProd, minProd = minProd, maxProd
        
        maxProd = max(nums[i], maxProd * nums[i])
        minProd = min(nums[i], minProd * nums[i])
        
        result = max(result, maxProd)
    
    return result

def main():
    nums1 = [2, 3, -2, 4]
    print("Max Product:", maxProduct(nums1))  # Output: 6
    
    nums2 = [-2, 0, -1]
    print("Max Product:", maxProduct(nums2))  # Output: 0
    
    nums3 = [-2, 3, -4]
    print("Max Product:", maxProduct(nums3))  # Output: 24

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""
