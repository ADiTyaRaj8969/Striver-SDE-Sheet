"""
Problem: Search in Rotated Sorted Array II (with duplicates)
Description: Search target in rotated sorted array that may contain duplicates.

Approach: Modified binary search. Handle duplicates by shrinking search space when arr[low] == arr[mid] == arr[high].
"""

from typing import List

def searchRotated(nums: List[int], target: int) -> bool:
    low, high = 0, len(nums) - 1
    
    while low <= high:
        mid = (low + high) // 2
        
        if nums[mid] == target:
            return True
        
        # Handle duplicates
        if nums[low] == nums[mid] == nums[high]:
            low += 1
            high -= 1
            continue
        
        # Check which half is sorted
        if nums[low] <= nums[mid]:
            # Left half is sorted
            if nums[low] <= target < nums[mid]:
                high = mid - 1
            else:
                low = mid + 1
        else:
            # Right half is sorted
            if nums[mid] < target <= nums[high]:
                low = mid + 1
            else:
                high = mid - 1
    
    return False

def main():
    nums = [2, 5, 6, 0, 0, 1, 2]
    target = 0
    
    print(f"Found: {'Yes' if searchRotated(nums, target) else 'No'}")
    # Output: Yes

if __name__ == "__main__":
    main()

"""
Time Complexity: O(log n) average, O(n) worst case with duplicates
Space Complexity: O(1)
"""
