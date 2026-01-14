"""
Problem: Kth Element of Two Sorted Arrays
Description: Find kth element in union of two sorted arrays without merging.

Approach: Binary search on smaller array. Partition arrays such that left half has k elements.
"""

from typing import List

def kthElement(arr1: List[int], arr2: List[int], k: int) -> int:
    n1, n2 = len(arr1), len(arr2)
    
    if n1 > n2:
        return kthElement(arr2, arr1, k)
    
    low = max(0, k - n2)
    high = min(k, n1)
    
    while low <= high:
        cut1 = (low + high) // 2
        cut2 = k - cut1
        
        left1 = float('-inf') if cut1 == 0 else arr1[cut1 - 1]
        left2 = float('-inf') if cut2 == 0 else arr2[cut2 - 1]
        right1 = float('inf') if cut1 == n1 else arr1[cut1]
        right2 = float('inf') if cut2 == n2 else arr2[cut2]
        
        if left1 <= right2 and left2 <= right1:
            return max(left1, left2)
        elif left1 > right2:
            high = cut1 - 1
        else:
            low = cut1 + 1
    
    return -1

def main():
    arr1 = [2, 3, 6, 7, 9]
    arr2 = [1, 4, 8, 10]
    k = 5
    
    print(f"{k}th element: {kthElement(arr1, arr2, k)}")
    # Output: 6

if __name__ == "__main__":
    main()

"""
Time Complexity: O(log(min(n1, n2)))
Space Complexity: O(1)
"""
