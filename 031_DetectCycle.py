"""
Problem: Detect Cycle in Linked List
Description: Check if a linked list has a cycle (loop).

Approach: Use Floyd's Cycle Detection (slow and fast pointers).
          If they meet, there's a cycle.
"""

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False
        
        slow = head
        fast = head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            if slow == fast:
                return True
        
        return False

if __name__ == "__main__":
    head = ListNode(3)
    head.next = ListNode(2)
    head.next.next = ListNode(0)
    head.next.next.next = ListNode(-4)
    head.next.next.next.next = head.next  # Create cycle
    
    sol = Solution()
    print(f"Has Cycle: {'Yes' if sol.hasCycle(head) else 'No'}")

"""
Time Complexity: O(n) where n is the number of nodes
Space Complexity: O(1)
"""
