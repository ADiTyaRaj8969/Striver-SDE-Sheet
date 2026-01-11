"""
Problem: Stock Span
Description: Find the span of stock prices. Span is the maximum number
             of consecutive days before current day with price <= current price.

Approach: Use monotonic decreasing stack to track indices of prices.
"""

class StockSpanner:
    def __init__(self):
        self.stack = []  # [(price, span)]
    
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
Time Complexity: O(1) amortized per call
Space Complexity: O(n)
"""
