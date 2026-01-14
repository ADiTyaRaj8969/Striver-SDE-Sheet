"""
Problem: Implement Queue using Stacks
Description: Implement queue operations (enqueue, dequeue, peek) using stack(s).

Approach: Use two stacks. Input stack for enqueue. Transfer to output stack for dequeue/peek when needed.
"""

class MyQueue:
    def __init__(self):
        self.input = []
        self.output = []
    
    def _transfer(self):
        if not self.output:
            while self.input:
                self.output.append(self.input.pop())
    
    def push(self, x: int) -> None:
        self.input.append(x)
    
    def pop(self) -> int:
        self._transfer()
        return self.output.pop()
    
    def peek(self) -> int:
        self._transfer()
        return self.output[-1]
    
    def empty(self) -> bool:
        return not self.input and not self.output

def main():
    queue = MyQueue()
    queue.push(1)
    queue.push(2)
    print(f"Peek: {queue.peek()}")     # Output: 1
    print(f"Pop: {queue.pop()}")       # Output: 1
    print(f"Empty: {queue.empty()}")   # Output: False

if __name__ == "__main__":
    main()

"""
Time Complexity: push O(1), pop/peek O(1) amortized
Space Complexity: O(n)
"""
