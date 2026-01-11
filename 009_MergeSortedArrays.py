"""
Problem: Merge Sorted Arrays
Description: Merge two sorted arrays into one sorted array without using extra space.
             nums1 has enough space to hold both arrays.

Approach: Fill nums1 from the end using three pointers - for nums1, nums2, and merged position.
"""

from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i = m - 1       # Last element in nums1
        j = n - 1       # Last element in nums2
        k = m + n - 1   # Last position in merged array
        
        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1

if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 2, 3, 0, 0, 0]
    nums2 = [2, 5, 6]
    m, n = 3, 3
    
    sol.merge(nums1, m, nums2, n)
    print(nums1)

"""
Time Complexity: O(m + n) where m and n are lengths of the two arrays
Space Complexity: O(1) - in-place merging
"""
