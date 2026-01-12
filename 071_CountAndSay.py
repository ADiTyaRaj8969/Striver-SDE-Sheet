"""
Problem: Count and Say
Description: Generate the nth term of the count-and-say sequence.

Approach: Iteratively build each term by counting consecutive digits.
"""

def countAndSay(n: int) -> str:
    if n == 1:
        return "1"
    
    result = "1"
    
    for _ in range(2, n + 1):
        next_str = ""
        count = 1
        
        for j in range(1, len(result)):
            if result[j] == result[j - 1]:
                count += 1
            else:
                next_str += str(count) + result[j - 1]
                count = 1
        
        next_str += str(count) + result[-1]
        result = next_str
    
    return result

def main():
    print(countAndSay(1))  # Output: "1"
    print(countAndSay(4))  # Output: "1211"
    print(countAndSay(5))  # Output: "111221"

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n * m) where m is length of previous term
Space Complexity: O(m)
"""
