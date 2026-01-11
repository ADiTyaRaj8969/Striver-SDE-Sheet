"""
Problem: Subset Sums
Description: Find the sums of all possible subsets of a given array.

Approach: Use recursion/backtracking. For each element, either include or exclude it.
"""

from typing import List

class Solution:
    def findSubsetSums(self, index: int, current_sum: int, arr: List[int], result: List[int]):
        if index == len(arr):
            result.append(current_sum)
            return
        
        # Include current element
        self.findSubsetSums(index + 1, current_sum + arr[index], arr, result)
        
        # Exclude current element
        self.findSubsetSums(index + 1, current_sum, arr, result)
    
    def subsetSums(self, arr: List[int]) -> List[int]:
        result = []
        self.findSubsetSums(0, 0, arr, result)
        result.sort()
        return result

if __name__ == "__main__":
    sol = Solution()
    arr = [2, 3]
    result = sol.subsetSums(arr)
    print(f"Subset Sums: {result}")

"""
Time Complexity: O(2^n) where n is the size of array
Space Complexity: O(2^n) for storing all subsets
"""
