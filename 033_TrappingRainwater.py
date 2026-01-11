"""
Problem: Trapping Rainwater
Description: Calculate the total amount of rainwater that can be trapped between bars.

Approach: Use two pointers from both ends. Track max heights from left and right.
          Water trapped at position = min(leftMax, rightMax) - height[i]
"""

from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        
        left, right = 0, len(height) - 1
        left_max, right_max = 0, 0
        water = 0
        
        while left < right:
            if height[left] < height[right]:
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    water += left_max - height[left]
                left += 1
            else:
                if height[right] >= right_max:
                    right_max = height[right]
                else:
                    water += right_max - height[right]
                right -= 1
        
        return water

if __name__ == "__main__":
    sol = Solution()
    height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(f"Water Trapped: {sol.trap(height)}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
"""
