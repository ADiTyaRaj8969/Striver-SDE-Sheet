"""
Problem: Single Element in Sorted Array
Description: Find element that appears once in sorted array where every other element appears twice.

Approach: Use binary search. Check if mid is at even/odd index and compare with neighbors.
"""

from typing import List

def singleNonDuplicate(nums: List[int]) -> int:
    n = len(nums)
    
    if n == 1:
        return nums[0]
    if nums[0] != nums[1]:
        return nums[0]
    if nums[n-1] != nums[n-2]:
        return nums[n-1]
    
    low, high = 1, n - 2
    
    while low <= high:
        mid = (low + high) // 2
        
        if nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]:
            return nums[mid]
        
        # Check which side single element is
        if ((mid % 2 == 0 and nums[mid] == nums[mid+1]) or
            (mid % 2 == 1 and nums[mid] == nums[mid-1])):
            low = mid + 1
        else:
            high = mid - 1
    
    return -1

def main():
    nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]
    
    print(f"Single element: {singleNonDuplicate(nums)}")
    # Output: 2

if __name__ == "__main__":
    main()

"""
Time Complexity: O(log n)
Space Complexity: O(1)
"""
