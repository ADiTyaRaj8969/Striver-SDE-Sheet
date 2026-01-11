"""
Problem: N Meetings in One Room
Description: Find the maximum number of meetings that can be held in one room.

Approach: Sort meetings by end time. Greedily select meetings that don't overlap.
"""

from typing import List

class Solution:
    def maxMeetings(self, start: List[int], end: List[int], n: int) -> int:
        meetings = [(end[i], start[i]) for i in range(n)]
        
        # Sort by end time
        meetings.sort()
        
        count = 1
        last_end_time = meetings[0][0]
        
        for i in range(1, n):
            if meetings[i][1] > last_end_time:
                count += 1
                last_end_time = meetings[i][0]
        
        return count

if __name__ == "__main__":
    sol = Solution()
    start = [1, 3, 0, 5, 8, 5]
    end = [2, 4, 6, 7, 9, 9]
    n = 6
    
    print(f"Maximum Meetings: {sol.maxMeetings(start, end, n)}")

"""
Time Complexity: O(n log n) due to sorting
Space Complexity: O(n) for storing meetings
"""
