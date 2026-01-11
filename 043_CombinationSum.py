"""
Problem: Combination Sum
Description: Find all unique combinations in an array that sum to a target.
             Same number may be chosen unlimited times.

Approach: Use backtracking. At each step, either include current element
          (and stay at same index) or move to next element.
"""

from typing import List

class Solution:
    def findCombinations(self, index: int, target: int, candidates: List[int],
                        current: List[int], result: List[List[int]]):
        if index == len(candidates):
            if target == 0:
                result.append(current[:])
            return
        
        # Include current element (can repeat)
        if candidates[index] <= target:
            current.append(candidates[index])
            self.findCombinations(index, target - candidates[index], candidates, current, result)
            current.pop()
        
        # Move to next element
        self.findCombinations(index + 1, target, candidates, current, result)
    
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        current = []
        self.findCombinations(0, target, candidates, current, result)
        return result

if __name__ == "__main__":
    sol = Solution()
    candidates = [2, 3, 6, 7]
    target = 7
    result = sol.combinationSum(candidates, target)
    
    print("Combinations:")
    for comb in result:
        print(comb)

"""
Time Complexity: O(2^t) where t is the target value
Space Complexity: O(t) for recursion depth
"""
