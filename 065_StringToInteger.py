"""
Problem: String to Integer (atoi)
Description: Implement atoi which converts a string to an integer.

Approach: Handle whitespace, sign, overflow, and invalid characters.
"""

def myAtoi(s: str) -> int:
    i = 0
    n = len(s)
    
    # Skip whitespace
    while i < n and s[i] == ' ':
        i += 1
    
    # Check sign
    sign = 1
    if i < n and (s[i] == '+' or s[i] == '-'):
        sign = -1 if s[i] == '-' else 1
        i += 1
    
    # Convert digits
    result = 0
    while i < n and s[i].isdigit():
        result = result * 10 + int(s[i])
        
        # Check overflow
        if sign == 1 and result > 2**31 - 1:
            return 2**31 - 1
        if sign == -1 and result > 2**31:
            return -2**31
        
        i += 1
    
    return sign * result

def main():
    print(myAtoi("42"))              # Output: 42
    print(myAtoi("   -42"))          # Output: -42
    print(myAtoi("4193 with words")) # Output: 4193
    print(myAtoi("words and 987"))   # Output: 0

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""
