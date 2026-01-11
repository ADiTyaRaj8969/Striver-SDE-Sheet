"""
Problem: Remove N-th Node from End of List
Description: Remove the N-th node from the end of a linked list.

Approach: Use two pointers with N gap between them. When fast reaches end,
          slow is at the node before the one to delete.
"""

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        
        fast = dummy
        slow = dummy
        
        # Move fast n+1 steps ahead
        for _ in range(n + 1):
            fast = fast.next
        
        # Move both until fast reaches end
        while fast:
            fast = fast.next
            slow = slow.next
        
        # Remove the node
        slow.next = slow.next.next
        
        return dummy.next

if __name__ == "__main__":
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    
    sol = Solution()
    head = sol.removeNthFromEnd(head, 2)
    
    print("List after removal: ", end="")
    while head:
        print(head.val, end=" ")
        head = head.next
    print()

"""
Time Complexity: O(n) where n is the number of nodes
Space Complexity: O(1)
"""
