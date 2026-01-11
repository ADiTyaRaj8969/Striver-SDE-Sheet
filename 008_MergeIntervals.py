"""
Problem: Merge Overlapping Intervals
Description: Given a collection of intervals, merge all overlapping intervals.

Approach: 1. Sort intervals by start time
          2. Iterate and merge intervals that overlap
"""

from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        
        intervals.sort()
        result = [intervals[0]]
        
        for i in range(1, len(intervals)):
            if result[-1][1] >= intervals[i][0]:
                # Overlapping intervals, merge them
                result[-1][1] = max(result[-1][1], intervals[i][1])
            else:
                # Non-overlapping interval
                result.append(intervals[i])
        
        return result

if __name__ == "__main__":
    sol = Solution()
    intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
    result = sol.merge(intervals)
    print(result)

"""
Time Complexity: O(n log n) due to sorting, where n is the number of intervals
Space Complexity: O(n) for the result array
"""
