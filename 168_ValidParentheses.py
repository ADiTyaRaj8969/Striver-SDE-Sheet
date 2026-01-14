"""
Problem: Check for Balanced Parentheses
Description: Check if string has balanced parentheses - (), {}, [].

Approach: Use stack. Push opening brackets. For closing, check if matching opening is on top.
"""

def isValid(s: str) -> bool:
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    
    for c in s:
        if c in '({[':
            stack.append(c)
        else:
            if not stack or stack[-1] != mapping[c]:
                return False
            stack.pop()
    
    return len(stack) == 0

def main():
    s1 = "()[]{}"
    print(f"{s1} is {'valid' if isValid(s1) else 'invalid'}")
    # Output: valid
    
    s2 = "([)]"
    print(f"{s2} is {'valid' if isValid(s2) else 'invalid'}")
    # Output: invalid

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
