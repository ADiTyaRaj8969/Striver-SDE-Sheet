"""
Problem: Reverse a Linked List
Description: Reverse a singly linked list.

Approach: Use three pointers (prev, curr, next) to reverse links iteratively.
"""

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        
        return prev
    
    # Recursive approach
    def reverseListRecursive(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        new_head = self.reverseListRecursive(head.next)
        head.next.next = head
        head.next = None
        
        return new_head

if __name__ == "__main__":
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    
    sol = Solution()
    reversed_head = sol.reverseList(head)
    
    print("Reversed List: ", end="")
    while reversed_head:
        print(reversed_head.val, end=" ")
        reversed_head = reversed_head.next
    print()

"""
Time Complexity: O(n) where n is the number of nodes
Space Complexity: O(1) for iterative, O(n) for recursive (call stack)
"""
