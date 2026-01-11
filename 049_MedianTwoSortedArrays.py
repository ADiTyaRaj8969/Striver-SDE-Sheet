"""
Problem: Median of Two Sorted Arrays
Description: Find the median of two sorted arrays of different sizes.

Approach: Use binary search on the smaller array. Partition both arrays such that
          left half elements ≤ right half elements.
"""

from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        
        m, n = len(nums1), len(nums2)
        left, right = 0, m
        
        while left <= right:
            partition1 = (left + right) // 2
            partition2 = (m + n + 1) // 2 - partition1
            
            maxLeft1 = float('-inf') if partition1 == 0 else nums1[partition1 - 1]
            minRight1 = float('inf') if partition1 == m else nums1[partition1]
            
            maxLeft2 = float('-inf') if partition2 == 0 else nums2[partition2 - 1]
            minRight2 = float('inf') if partition2 == n else nums2[partition2]
            
            if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
                if (m + n) % 2 == 0:
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0
                else:
                    return max(maxLeft1, maxLeft2)
            elif maxLeft1 > minRight2:
                right = partition1 - 1
            else:
                left = partition1 + 1
        
        return 0.0

if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 3]
    nums2 = [2]
    
    print(f"Median: {sol.findMedianSortedArrays(nums1, nums2)}")

"""
Time Complexity: O(log(min(m, n))) where m and n are sizes of arrays
Space Complexity: O(1)
"""
