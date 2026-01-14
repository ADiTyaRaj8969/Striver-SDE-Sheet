"""
Problem: Implement Stack using Queues
Description: Implement stack operations (push, pop, top) using queue(s).

Approach: Use one queue. For push, add element and rotate queue to make new element front.
"""

from collections import deque

class MyStack:
    def __init__(self):
        self.q = deque()
    
    def push(self, x: int) -> None:
        size = len(self.q)
        self.q.append(x)
        for _ in range(size):
            self.q.append(self.q.popleft())
    
    def pop(self) -> int:
        return self.q.popleft()
    
    def top(self) -> int:
        return self.q[0]
    
    def empty(self) -> bool:
        return len(self.q) == 0

def main():
    stack = MyStack()
    stack.push(1)
    stack.push(2)
    print(f"Top: {stack.top()}")      # Output: 2
    print(f"Pop: {stack.pop()}")      # Output: 2
    print(f"Empty: {stack.empty()}")  # Output: False

if __name__ == "__main__":
    main()

"""
Time Complexity: push O(n), pop/top/empty O(1)
Space Complexity: O(n)
"""
