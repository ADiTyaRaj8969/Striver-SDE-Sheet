"""
Problem: Kth Largest Element
Description: Find the k-th largest element in an unsorted array.

Approach: Use min heap of size k. Maintain k largest elements in heap.
          Root is the k-th largest.
"""

from typing import List
import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_heap = []
        
        for num in nums:
            heapq.heappush(min_heap, num)
            
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        
        return min_heap[0]
    
    # Alternative: Using nlargest
    def findKthLargestSimple(self, nums: List[int], k: int) -> int:
        return heapq.nlargest(k, nums)[-1]

if __name__ == "__main__":
    sol = Solution()
    nums = [3, 2, 1, 5, 6, 4]
    k = 2
    
    print(f"Kth Largest: {sol.findKthLargest(nums, k)}")

"""
Time Complexity: O(n log k) for heap approach
Space Complexity: O(k) for heap
"""
