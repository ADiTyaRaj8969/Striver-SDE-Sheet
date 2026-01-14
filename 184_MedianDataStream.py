"""
Problem: Find Median from Data Stream
Description: Design data structure to find median from stream of numbers.

Approach: Use two heaps - max heap for smaller half, min heap for larger half. Balance sizes.
"""

import heapq

class MedianFinder:
    def __init__(self):
        self.maxHeap = []  # smaller half (negated for max heap)
        self.minHeap = []  # larger half
    
    def addNum(self, num: int) -> None:
        if not self.maxHeap or num <= -self.maxHeap[0]:
            heapq.heappush(self.maxHeap, -num)
        else:
            heapq.heappush(self.minHeap, num)
        
        # Balance heaps
        if len(self.maxHeap) > len(self.minHeap) + 1:
            heapq.heappush(self.minHeap, -heapq.heappop(self.maxHeap))
        elif len(self.minHeap) > len(self.maxHeap):
            heapq.heappush(self.maxHeap, -heapq.heappop(self.minHeap))
    
    def findMedian(self) -> float:
        if len(self.maxHeap) > len(self.minHeap):
            return -self.maxHeap[0]
        return (-self.maxHeap[0] + self.minHeap[0]) / 2.0

def main():
    mf = MedianFinder()
    mf.addNum(1)
    mf.addNum(2)
    print(f"Median: {mf.findMedian()}")  # 1.5
    mf.addNum(3)
    print(f"Median: {mf.findMedian()}")  # 2

if __name__ == "__main__":
    main()

"""
Time Complexity: addNum O(log n), findMedian O(1)
Space Complexity: O(n)
"""
