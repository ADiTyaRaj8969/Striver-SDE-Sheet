"""
Problem: Partition Equal Subset Sum
Description: Determine if array can be partitioned into two subsets with equal sum.

Approach: This is a subset sum problem. Find if there's a subset with sum = total/2.
          Use DP similar to 0-1 knapsack.
"""

from typing import List

def canPartition(nums: List[int]) -> bool:
    total = sum(nums)
    
    if total % 2 != 0:
        return False
    
    target = total // 2
    dp = [False] * (target + 1)
    dp[0] = True
    
    for num in nums:
        for j in range(target, num - 1, -1):
            dp[j] = dp[j] or dp[j - num]
    
    return dp[target]

def main():
    nums1 = [1, 5, 11, 5]
    print("Can partition:", canPartition(nums1))  # Output: True
    
    nums2 = [1, 2, 3, 5]
    print("Can partition:", canPartition(nums2))  # Output: False

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n * sum)
Space Complexity: O(sum)
"""
