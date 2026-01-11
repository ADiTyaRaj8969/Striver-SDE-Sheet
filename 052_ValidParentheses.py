"""
Problem: Valid Parentheses (Balanced Parentheses)
Description: Check if a string of parentheses (), {}, [] is valid and balanced.

Approach: Use stack. Push opening brackets, pop and match with closing brackets.
"""

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {')': '(', '}': '{', ']': '['}
        
        for char in s:
            if char in mapping:
                top_element = stack.pop() if stack else '#'
                
                if mapping[char] != top_element:
                    return False
            else:
                stack.append(char)
        
        return not stack

if __name__ == "__main__":
    sol = Solution()
    s = "()[]{}"
    
    print(f"Is Valid: {'Yes' if sol.isValid(s) else 'No'}")

"""
Time Complexity: O(n) where n is the length of string
Space Complexity: O(n) for the stack
"""
