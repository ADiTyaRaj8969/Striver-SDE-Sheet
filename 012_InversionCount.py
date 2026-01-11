"""
Problem: Inversion of Array (Count Inversions)
Description: Count pairs (i, j) such that i < j and arr[i] > arr[j].

Approach: Use modified merge sort to count inversions while sorting.
          During merge, count inversions when element from right is smaller.
"""

from typing import List

class Solution:
    def merge_and_count(self, arr: List[int], left: int, mid: int, right: int) -> int:
        temp = []
        i, j = left, mid + 1
        inv_count = 0
        
        while i <= mid and j <= right:
            if arr[i] <= arr[j]:
                temp.append(arr[i])
                i += 1
            else:
                temp.append(arr[j])
                inv_count += (mid - i + 1)
                j += 1
        
        while i <= mid:
            temp.append(arr[i])
            i += 1
        
        while j <= right:
            temp.append(arr[j])
            j += 1
        
        for i in range(len(temp)):
            arr[left + i] = temp[i]
        
        return inv_count
    
    def merge_sort_and_count(self, arr: List[int], left: int, right: int) -> int:
        inv_count = 0
        if left < right:
            mid = left + (right - left) // 2
            inv_count += self.merge_sort_and_count(arr, left, mid)
            inv_count += self.merge_sort_and_count(arr, mid + 1, right)
            inv_count += self.merge_and_count(arr, left, mid, right)
        return inv_count
    
    def inversionCount(self, arr: List[int]) -> int:
        return self.merge_sort_and_count(arr, 0, len(arr) - 1)

if __name__ == "__main__":
    sol = Solution()
    arr = [5, 3, 2, 4, 1]
    print(f"Inversion Count: {sol.inversionCount(arr)}")

"""
Time Complexity: O(n log n) where n is the length of the array
Space Complexity: O(n) for temporary array during merge
"""
