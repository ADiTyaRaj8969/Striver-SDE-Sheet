"""
Problem: Power(x, n)
Description: Calculate x raised to the power of n (x^n) efficiently.

Approach: Use binary exponentiation (exponentiation by squaring).
          If n is even: x^n = (x^2)^(n/2)
          If n is odd: x^n = x * x^(n-1)
"""

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1.0
        
        N = n
        if N < 0:
            x = 1 / x
            N = -N
        
        result = 1.0
        current = x
        
        while N > 0:
            if N % 2 == 1:
                result *= current
            current *= current
            N //= 2
        
        return result

if __name__ == "__main__":
    sol = Solution()
    x, n = 2.0, 10
    print(f"{x}^{n} = {sol.myPow(x, n)}")

"""
Time Complexity: O(log n) where n is the exponent
Space Complexity: O(1)
"""
