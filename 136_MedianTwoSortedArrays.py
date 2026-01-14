"""
Problem: Median of Two Sorted Arrays
Description: Find median of two sorted arrays in O(log(min(m,n))) time.

Approach: Binary search on the smaller array to find correct partition.
          Partition arrays such that left half has same size as right half.
"""

from typing import List

def findMedianSortedArrays(nums1: List[int], nums2: List[int]) -> float:
    if len(nums1) > len(nums2):
        return findMedianSortedArrays(nums2, nums1)
    
    m, n = len(nums1), len(nums2)
    low, high = 0, m
    
    while low <= high:
        partition1 = (low + high) // 2
        partition2 = (m + n + 1) // 2 - partition1
        
        maxLeft1 = float('-inf') if partition1 == 0 else nums1[partition1 - 1]
        minRight1 = float('inf') if partition1 == m else nums1[partition1]
        
        maxLeft2 = float('-inf') if partition2 == 0 else nums2[partition2 - 1]
        minRight2 = float('inf') if partition2 == n else nums2[partition2]
        
        if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
            if (m + n) % 2 == 0:
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0
            else:
                return float(max(maxLeft1, maxLeft2))
        elif maxLeft1 > minRight2:
            high = partition1 - 1
        else:
            low = partition1 + 1
    
    return 0.0

def main():
    nums1 = [1, 3]
    nums2 = [2]
    print("Median:", findMedianSortedArrays(nums1, nums2))  # Output: 2.0
    
    nums3 = [1, 2]
    nums4 = [3, 4]
    print("Median:", findMedianSortedArrays(nums3, nums4))  # Output: 2.5

if __name__ == "__main__":
    main()

"""
Time Complexity: O(log(min(m, n)))
Space Complexity: O(1)
"""
