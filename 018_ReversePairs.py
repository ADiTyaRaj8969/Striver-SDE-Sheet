"""
Problem: Reverse Pairs
Description: Count pairs (i, j) such that i < j and arr[i] > 2 * arr[j].

Approach: Use modified merge sort similar to inversion count.
          Count reverse pairs during the merge process.
"""

from typing import List

class Solution:
    def countPairs(self, nums: List[int], left: int, mid: int, right: int) -> int:
        count = 0
        j = mid + 1
        
        for i in range(left, mid + 1):
            while j <= right and nums[i] > 2 * nums[j]:
                j += 1
            count += (j - (mid + 1))
        
        return count
    
    def merge(self, nums: List[int], left: int, mid: int, right: int):
        temp = []
        i, j = left, mid + 1
        
        while i <= mid and j <= right:
            if nums[i] <= nums[j]:
                temp.append(nums[i])
                i += 1
            else:
                temp.append(nums[j])
                j += 1
        
        while i <= mid:
            temp.append(nums[i])
            i += 1
        
        while j <= right:
            temp.append(nums[j])
            j += 1
        
        for i in range(len(temp)):
            nums[left + i] = temp[i]
    
    def mergeSort(self, nums: List[int], left: int, right: int) -> int:
        if left >= right:
            return 0
        
        mid = left + (right - left) // 2
        count = self.mergeSort(nums, left, mid)
        count += self.mergeSort(nums, mid + 1, right)
        count += self.countPairs(nums, left, mid, right)
        self.merge(nums, left, mid, right)
        
        return count
    
    def reversePairs(self, nums: List[int]) -> int:
        return self.mergeSort(nums, 0, len(nums) - 1)

if __name__ == "__main__":
    sol = Solution()
    nums = [1, 3, 2, 3, 1]
    print(f"Reverse Pairs: {sol.reversePairs(nums)}")

"""
Time Complexity: O(n log n) where n is the length of the array
Space Complexity: O(n) for temporary array during merge
"""
