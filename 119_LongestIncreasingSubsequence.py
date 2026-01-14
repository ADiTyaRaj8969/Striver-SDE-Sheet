"""
Problem: Longest Increasing Subsequence (LIS)
Description: Find the length of the longest strictly increasing subsequence.

Approach 1: DP - dp[i] = length of LIS ending at index i. O(n^2)
Approach 2: Binary Search - Maintain array of smallest tail elements. O(n log n)
"""

from typing import List
import bisect

# Approach 1: DP - O(n^2)
def lengthOfLIS_DP(nums: List[int]) -> int:
    n = len(nums)
    if n == 0:
        return 0
    
    dp = [1] * n
    
    for i in range(1, n):
        for j in range(i):
            if nums[j] < nums[i]:
                dp[i] = max(dp[i], dp[j] + 1)
    
    return max(dp)

# Approach 2: Binary Search - O(n log n)
def lengthOfLIS(nums: List[int]) -> int:
    tails = []
    
    for num in nums:
        pos = bisect.bisect_left(tails, num)
        
        if pos == len(tails):
            tails.append(num)
        else:
            tails[pos] = num
    
    return len(tails)

def main():
    nums1 = [10, 9, 2, 5, 3, 7, 101, 18]
    print("Length of LIS (DP):", lengthOfLIS_DP(nums1))  # Output: 4
    print("Length of LIS (Binary Search):", lengthOfLIS(nums1))  # Output: 4
    
    nums2 = [0, 1, 0, 3, 2, 3]
    print("Length of LIS:", lengthOfLIS(nums2))  # Output: 4

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n) for binary search approach
Space Complexity: O(n)
"""
