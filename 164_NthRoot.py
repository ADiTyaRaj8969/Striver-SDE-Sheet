"""
Problem: Nth Root of Integer
Description: Find nth root of integer M. Return -1 if root doesn't exist.

Approach: Binary search on range [1, M]. Check if mid^n equals M.
"""

def power(base: int, exp: int, limit: int) -> int:
    result = 1
    for _ in range(exp):
        result *= base
        if result > limit:
            return limit + 1
    return result

def nthRoot(n: int, m: int) -> int:
    low, high = 1, m
    
    while low <= high:
        mid = (low + high) // 2
        val = power(mid, n, m)
        
        if val == m:
            return mid
        elif val < m:
            low = mid + 1
        else:
            high = mid - 1
    
    return -1

def main():
    n, m = 3, 27
    print(f"{n}th root of {m} is: {nthRoot(n, m)}")
    # Output: 3
    
    n, m = 4, 69
    print(f"{n}th root of {m} is: {nthRoot(n, m)}")
    # Output: -1

if __name__ == "__main__":
    main()

"""
Time Complexity: O(log m * n)
Space Complexity: O(1)
"""
