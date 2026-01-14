"""
Problem: K Most Frequent Elements
Description: Find k most frequent elements in array.

Approach: Use hashmap for frequencies. Use min heap of size k or bucket sort.
"""

from typing import List
from collections import Counter
import heapq

def topKFrequent(nums: List[int], k: int) -> List[int]:
    freq = Counter(nums)
    
    # Min heap of size k
    minHeap = []
    
    for num, count in freq.items():
        heapq.heappush(minHeap, (count, num))
        if len(minHeap) > k:
            heapq.heappop(minHeap)
    
    return [num for count, num in minHeap]

# Bucket sort approach - O(n)
def topKFrequentBucket(nums: List[int], k: int) -> List[int]:
    freq = Counter(nums)
    n = len(nums)
    bucket = [[] for _ in range(n + 1)]
    
    for num, count in freq.items():
        bucket[count].append(num)
    
    result = []
    for i in range(n, -1, -1):
        for num in bucket[i]:
            result.append(num)
            if len(result) == k:
                return result
    
    return result

def main():
    nums = [1, 1, 1, 2, 2, 3]
    k = 2
    
    result = topKFrequent(nums, k)
    
    print(f"Top {k} frequent elements: {result}")
    # Output: [1, 2]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log k) with heap, O(n) with bucket sort
Space Complexity: O(n)
"""
