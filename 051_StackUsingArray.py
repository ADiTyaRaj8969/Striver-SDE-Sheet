"""
Problem: Implement Stack using Array
Description: Build a stack data structure using only an array.

Approach: Use list with append/pop operations. Push adds element, pop removes from end.
"""

class Stack:
    def __init__(self, capacity: int):
        self.arr = []
        self.capacity = capacity
    
    def push(self, x: int) -> None:
        if len(self.arr) >= self.capacity:
            print("Stack Overflow")
            return
        self.arr.append(x)
    
    def pop(self) -> int:
        if not self.arr:
            print("Stack Underflow")
            return -1
        return self.arr.pop()
    
    def peek(self) -> int:
        if not self.arr:
            print("Stack is Empty")
            return -1
        return self.arr[-1]
    
    def isEmpty(self) -> bool:
        return len(self.arr) == 0
    
    def size(self) -> int:
        return len(self.arr)

if __name__ == "__main__":
    s = Stack(5)
    
    s.push(10)
    s.push(20)
    s.push(30)
    
    print(f"Top element: {s.peek()}")
    print(f"Popped: {s.pop()}")
    print(f"Stack size: {s.size()}")

"""
Time Complexity: O(1) for all operations
Space Complexity: O(n) where n is stack capacity
"""
