"""
Problem: Find Peak Element
Description: Find a peak element in array. Peak is element greater than its neighbors.

Approach: Binary search. Compare mid with mid+1. Move towards higher neighbor.
"""

from typing import List

def findPeakElement(nums: List[int]) -> int:
    n = len(nums)
    
    if n == 1:
        return 0
    if nums[0] > nums[1]:
        return 0
    if nums[n-1] > nums[n-2]:
        return n - 1
    
    low, high = 1, n - 2
    
    while low <= high:
        mid = (low + high) // 2
        
        if nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]:
            return mid
        elif nums[mid] < nums[mid+1]:
            low = mid + 1
        else:
            high = mid - 1
    
    return -1

def main():
    nums = [1, 2, 3, 1]
    
    print(f"Peak element at index: {findPeakElement(nums)}")
    # Output: 2

if __name__ == "__main__":
    main()

"""
Time Complexity: O(log n)
Space Complexity: O(1)
"""
