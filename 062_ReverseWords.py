"""
Problem: Reverse Words in a String
Description: Reverse the order of words in a string.

Approach: Split by spaces, filter empty strings, and join in reverse.
"""

def reverseWords(s: str) -> str:
    words = s.split()
    return ' '.join(reversed(words))

def main():
    s1 = "the sky is blue"
    print(reverseWords(s1))  # Output: "blue is sky the"
    
    s2 = "  hello world  "
    print(reverseWords(s2))  # Output: "world hello"
    
    s3 = "a good   example"
    print(reverseWords(s3))  # Output: "example good a"

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
