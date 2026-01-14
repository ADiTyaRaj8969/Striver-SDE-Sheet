"""
Problem: N Meetings in One Room
Description: Given start and end times of meetings, find max number of meetings that can be held in one room.

Approach: Sort meetings by end time. Greedily select meetings that don't overlap.
"""

from typing import List

class Meeting:
    def __init__(self, start: int, end: int, pos: int):
        self.start = start
        self.end = end
        self.pos = pos

def maxMeetings(start: List[int], end: List[int]) -> int:
    n = len(start)
    meetings = [Meeting(start[i], end[i], i + 1) for i in range(n)]
    
    meetings.sort(key=lambda x: (x.end, x.pos))
    
    count = 1
    lastEnd = meetings[0].end
    
    for i in range(1, n):
        if meetings[i].start > lastEnd:
            count += 1
            lastEnd = meetings[i].end
    
    return count

def main():
    start = [1, 3, 0, 5, 8, 5]
    end = [2, 4, 6, 7, 9, 9]
    
    print(f"Maximum meetings: {maxMeetings(start, end)}")
    # Output: 4

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n)
Space Complexity: O(n)
"""
