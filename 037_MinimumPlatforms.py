"""
Problem: Minimum Number of Platforms
Description: Find the minimum platforms required for a railway station to avoid delays.

Approach: Sort arrival and departure times separately. Use two pointers to track
          platforms needed at any time.
"""

from typing import List

class Solution:
    def findPlatform(self, arr: List[int], dep: List[int], n: int) -> int:
        arr.sort()
        dep.sort()
        
        platforms_needed = 0
        max_platforms = 0
        i, j = 0, 0
        
        while i < n:
            if arr[i] <= dep[j]:
                platforms_needed += 1
                i += 1
            else:
                platforms_needed -= 1
                j += 1
            
            max_platforms = max(max_platforms, platforms_needed)
        
        return max_platforms

if __name__ == "__main__":
    sol = Solution()
    arr = [900, 940, 950, 1100, 1500, 1800]
    dep = [910, 1200, 1120, 1130, 1900, 2000]
    n = 6
    
    print(f"Minimum Platforms Required: {sol.findPlatform(arr, dep, n)}")

"""
Time Complexity: O(n log n) due to sorting
Space Complexity: O(1)
"""
