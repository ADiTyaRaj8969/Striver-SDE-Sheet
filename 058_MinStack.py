"""
Problem: Min Stack
Description: Design a stack that supports push, pop, top, and retrieving
             the minimum element in constant time.

Approach: Use two stacks - one for elements, one for tracking minimums.
"""

class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []
    
    def push(self, val: int) -> None:
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)
    
    def pop(self) -> None:
        if self.stack[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        self.stack.pop()
    
    def top(self) -> int:
        return self.stack[-1]
    
    def getMin(self) -> int:
        return self.min_stack[-1]

def main():
    min_stack = MinStack()
    
    min_stack.push(-2)
    min_stack.push(0)
    min_stack.push(-3)
    print(min_stack.getMin())  # Output: -3
    min_stack.pop()
    print(min_stack.top())     # Output: 0
    print(min_stack.getMin())  # Output: -2

if __name__ == "__main__":
    main()

"""
Time Complexity: O(1) for all operations
Space Complexity: O(n)
"""
