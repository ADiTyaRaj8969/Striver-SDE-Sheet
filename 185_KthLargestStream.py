"""
Problem: K-th Largest Element in Stream
Description: Design class to find kth largest element in stream.

Approach: Use min heap of size k. Top element is kth largest.
"""

from typing import List
import heapq

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.minHeap = []
        for num in nums:
            self.add(num)
    
    def add(self, val: int) -> int:
        if len(self.minHeap) < self.k:
            heapq.heappush(self.minHeap, val)
        elif val > self.minHeap[0]:
            heapq.heappushpop(self.minHeap, val)
        
        return self.minHeap[0]

def main():
    nums = [4, 5, 8, 2]
    kl = KthLargest(3, nums)
    
    print(kl.add(3))   # Output: 4
    print(kl.add(5))   # Output: 5
    print(kl.add(10))  # Output: 5
    print(kl.add(9))   # Output: 8
    print(kl.add(4))   # Output: 8

if __name__ == "__main__":
    main()

"""
Time Complexity: add O(log k), constructor O(n log k)
Space Complexity: O(k)
"""
