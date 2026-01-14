"""
Problem: Minimum Platforms
Description: Find minimum number of platforms needed for a railway station given arrival and departure times.

Approach: Sort arrival and departure times separately. Use two pointers to track overlapping trains.
"""

from typing import List

def findPlatform(arr: List[int], dep: List[int]) -> int:
    n = len(arr)
    arr.sort()
    dep.sort()
    
    platforms = 0
    maxPlatforms = 0
    i = j = 0
    
    while i < n and j < n:
        if arr[i] <= dep[j]:
            platforms += 1
            i += 1
            maxPlatforms = max(maxPlatforms, platforms)
        else:
            platforms -= 1
            j += 1
    
    return maxPlatforms

def main():
    arr = [900, 940, 950, 1100, 1500, 1800]
    dep = [910, 1200, 1120, 1130, 1900, 2000]
    
    print(f"Minimum platforms needed: {findPlatform(arr, dep)}")
    # Output: 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n)
Space Complexity: O(1)
"""
