"""
Problem: Distinct Numbers in Window
Description: Find count of distinct elements in every window of size K.

Approach: Use sliding window with hashmap to track element frequencies.
"""

from typing import List
from collections import defaultdict

def distinctInWindow(arr: List[int], k: int) -> List[int]:
    freq = defaultdict(int)
    result = []
    
    # First window
    for i in range(k):
        freq[arr[i]] += 1
    result.append(len(freq))
    
    # Slide window
    for i in range(k, len(arr)):
        # Remove leftmost element
        freq[arr[i-k]] -= 1
        if freq[arr[i-k]] == 0:
            del freq[arr[i-k]]
        
        # Add new element
        freq[arr[i]] += 1
        
        result.append(len(freq))
    
    return result

def main():
    arr = [1, 2, 1, 3, 4, 2, 3]
    k = 4
    
    result = distinctInWindow(arr, k)
    
    print("Distinct counts:", result)  # Output: [3, 4, 4, 3]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(k)
"""
