"""
Problem: Aggressive Cows
Description: Place C cows in N stalls such that minimum distance between any two cows is maximized.

Approach: Binary search on answer. For each mid distance, check if we can place all cows with min distance >= mid.
"""

from typing import List

def canPlaceCows(stalls: List[int], cows: int, minDist: int) -> bool:
    count = 1
    lastPos = stalls[0]
    
    for i in range(1, len(stalls)):
        if stalls[i] - lastPos >= minDist:
            count += 1
            lastPos = stalls[i]
            if count == cows:
                return True
    
    return False

def aggressiveCows(stalls: List[int], cows: int) -> int:
    stalls.sort()
    
    low = 1
    high = stalls[-1] - stalls[0]
    result = 0
    
    while low <= high:
        mid = (low + high) // 2
        
        if canPlaceCows(stalls, cows, mid):
            result = mid
            low = mid + 1
        else:
            high = mid - 1
    
    return result

def main():
    stalls = [1, 2, 4, 8, 9]
    cows = 3
    
    print(f"Maximum minimum distance: {aggressiveCows(stalls, cows)}")
    # Output: 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n + n log(max-min))
Space Complexity: O(1)
"""
