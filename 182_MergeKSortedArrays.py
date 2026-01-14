"""
Problem: Merge K Sorted Arrays
Description: Merge k sorted arrays into one sorted array.

Approach: Use min heap with (value, arrayIndex, elementIndex). Extract min and add next element from same array.
"""

from typing import List
import heapq

def mergeKArrays(arrays: List[List[int]]) -> List[int]:
    result = []
    minHeap = []
    
    # Add first element of each array
    for i, arr in enumerate(arrays):
        if arr:
            heapq.heappush(minHeap, (arr[0], i, 0))
    
    while minHeap:
        val, arrIdx, eleIdx = heapq.heappop(minHeap)
        result.append(val)
        
        # Add next element from same array
        if eleIdx + 1 < len(arrays[arrIdx]):
            heapq.heappush(minHeap, (arrays[arrIdx][eleIdx + 1], arrIdx, eleIdx + 1))
    
    return result

def main():
    arrays = [
        [1, 4, 7],
        [2, 5, 8],
        [3, 6, 9]
    ]
    
    result = mergeKArrays(arrays)
    
    print(f"Merged array: {result}")
    # Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log k) where n is total elements
Space Complexity: O(k + n)
"""
