"""
Problem: Find Middle of Linked List
Description: Find the middle node of a linked list. If there are two middle nodes,
             return the second middle node.

Approach: Use slow and fast pointer (tortoise and hare).
          When fast reaches end, slow is at middle.
"""

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        return slow

if __name__ == "__main__":
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    
    sol = Solution()
    middle = sol.middleNode(head)
    
    print(f"Middle Node: {middle.val}")

"""
Time Complexity: O(n) where n is the number of nodes
Space Complexity: O(1)
"""
