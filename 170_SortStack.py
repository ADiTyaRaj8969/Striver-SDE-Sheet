"""
Problem: Sort a Stack
Description: Sort a stack using recursion without using any other data structures.

Approach: Recursively pop all elements. Insert each element in sorted position.
"""

from typing import List

def insertSorted(stack: List[int], element: int) -> None:
    if not stack or stack[-1] < element:
        stack.append(element)
        return
    
    top = stack.pop()
    insertSorted(stack, element)
    stack.append(top)

def sortStack(stack: List[int]) -> None:
    if not stack:
        return
    
    top = stack.pop()
    sortStack(stack)
    insertSorted(stack, top)

def main():
    stack = [5, 1, 0, 2]
    
    sortStack(stack)
    
    print(f"Sorted stack (top to bottom): {stack[::-1]}")
    # Output: [5, 2, 1, 0]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n^2)
Space Complexity: O(n) for recursion
"""
