"""
Problem: Online Stock Span
Description: Calculate span of stock's price for current day. Span is max consecutive days with price <= today's price.

Approach: Use stack to store (price, span) pairs. Pop smaller prices and accumulate spans.
"""

from typing import List, Tuple

class StockSpanner:
    def __init__(self):
        self.stack: List[Tuple[int, int]] = []  # (price, span)
    
    def next(self, price: int) -> int:
        span = 1
        
        while self.stack and self.stack[-1][0] <= price:
            span += self.stack[-1][1]
            self.stack.pop()
        
        self.stack.append((price, span))
        return span

def main():
    spanner = StockSpanner()
    
    print(spanner.next(100))  # Output: 1
    print(spanner.next(80))   # Output: 1
    print(spanner.next(60))   # Output: 1
    print(spanner.next(70))   # Output: 2
    print(spanner.next(60))   # Output: 1
    print(spanner.next(75))   # Output: 4
    print(spanner.next(85))   # Output: 6

if __name__ == "__main__":
    main()

"""
Time Complexity: O(1) amortized
Space Complexity: O(n)
"""
