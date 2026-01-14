"""
Problem: Activity Selection Problem
Description: Select maximum number of activities that don't overlap given start and end times.

Approach: Sort by finish time. Greedily pick activities with earliest finish that don't conflict.
"""

from typing import List

class Activity:
    def __init__(self, start: int, finish: int, index: int):
        self.start = start
        self.finish = finish
        self.index = index

def activitySelection(start: List[int], finish: List[int]) -> int:
    n = len(start)
    activities = [Activity(start[i], finish[i], i) for i in range(n)]
    
    activities.sort(key=lambda x: x.finish)
    
    count = 1
    lastFinish = activities[0].finish
    
    for i in range(1, n):
        if activities[i].start >= lastFinish:
            count += 1
            lastFinish = activities[i].finish
    
    return count

def main():
    start = [1, 3, 0, 5, 8, 5]
    finish = [2, 4, 6, 7, 9, 9]
    
    print(f"Maximum activities: {activitySelection(start, finish)}")
    # Output: 4

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n)
Space Complexity: O(n)
"""
