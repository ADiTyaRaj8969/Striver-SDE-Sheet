"""
Problem: Roman to Integer
Description: Convert a Roman numeral string to an integer.

Approach: Iterate through string, subtract if current < next, else add.
"""

def romanToInt(s: str) -> int:
    roman = {
        'I': 1, 'V': 5, 'X': 10, 'L': 50,
        'C': 100, 'D': 500, 'M': 1000
    }
    
    result = 0
    
    for i in range(len(s)):
        if i + 1 < len(s) and roman[s[i]] < roman[s[i + 1]]:
            result -= roman[s[i]]
        else:
            result += roman[s[i]]
    
    return result

def main():
    print(romanToInt("III"))     # Output: 3
    print(romanToInt("LVIII"))   # Output: 58
    print(romanToInt("MCMXCIV")) # Output: 1994

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""
