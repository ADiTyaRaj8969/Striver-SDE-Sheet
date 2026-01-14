"""
Problem: Kth Largest Element in Array
Description: Find the kth largest element in an unsorted array.

Approach 1: Min heap of size k - O(n log k)
Approach 2: Quickselect - O(n) average, O(n^2) worst case
Approach 3: Sort - O(n log n)
"""

from typing import List
import heapq
import random

# Approach 1: Min Heap
def findKthLargest(nums: List[int], k: int) -> int:
    minHeap = []
    
    for num in nums:
        heapq.heappush(minHeap, num)
        if len(minHeap) > k:
            heapq.heappop(minHeap)
    
    return minHeap[0]

# Approach 2: Quickselect
def partition(nums: List[int], left: int, right: int) -> int:
    pivot = nums[right]
    i = left
    
    for j in range(left, right):
        if nums[j] > pivot:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
    
    nums[i], nums[right] = nums[right], nums[i]
    return i

def quickSelect(nums: List[int], left: int, right: int, k: int) -> int:
    if left == right:
        return nums[left]
    
    pivotIndex = partition(nums, left, right)
    
    if k == pivotIndex:
        return nums[k]
    elif k < pivotIndex:
        return quickSelect(nums, left, pivotIndex - 1, k)
    else:
        return quickSelect(nums, pivotIndex + 1, right, k)

def findKthLargestQuickselect(nums: List[int], k: int) -> int:
    return quickSelect(nums, 0, len(nums) - 1, k - 1)

def main():
    nums1 = [3, 2, 1, 5, 6, 4]
    k1 = 2
    print("Kth largest (Heap):", findKthLargest(nums1, k1))  # Output: 5
    
    nums2 = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    k2 = 4
    print("Kth largest (Quickselect):", findKthLargestQuickselect(nums2, k2))  # Output: 4

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log k) for heap, O(n) average for quickselect
Space Complexity: O(k) for heap, O(1) for quickselect
"""
