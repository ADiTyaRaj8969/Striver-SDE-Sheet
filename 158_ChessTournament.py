"""
Problem: Chess Tournament
Description: Place C players in N positions such that minimum distance between any two is maximized.

Approach: Binary search on minimum distance. Check if placement is possible with given distance constraint.
"""

from typing import List

def canPlace(positions: List[int], players: int, minDist: int) -> bool:
    count = 1
    lastPos = positions[0]
    
    for i in range(1, len(positions)):
        if positions[i] - lastPos >= minDist:
            count += 1
            lastPos = positions[i]
            if count == players:
                return True
    
    return False

def chessTournament(positions: List[int], players: int) -> int:
    positions.sort()
    
    low = 1
    high = positions[-1] - positions[0]
    result = 0
    
    while low <= high:
        mid = (low + high) // 2
        
        if canPlace(positions, players, mid):
            result = mid
            low = mid + 1
        else:
            high = mid - 1
    
    return result

def main():
    positions = [1, 2, 8, 4, 9]
    players = 3
    
    print(f"Maximum minimum distance: {chessTournament(positions, players)}")
    # Output: 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n + n log(max-min))
Space Complexity: O(1)
"""
