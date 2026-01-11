"""
Problem: Add Two Numbers as Linked List
Description: Add two numbers represented by linked lists where digits are stored in reverse order.

Approach: Traverse both lists, add corresponding digits with carry.
"""

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        tail = dummy
        carry = 0
        
        while l1 or l2 or carry:
            total = carry
            
            if l1:
                total += l1.val
                l1 = l1.next
            
            if l2:
                total += l2.val
                l2 = l2.next
            
            carry = total // 10
            tail.next = ListNode(total % 10)
            tail = tail.next
        
        return dummy.next

if __name__ == "__main__":
    # 342 + 465 = 807
    l1 = ListNode(2, ListNode(4, ListNode(3)))
    l2 = ListNode(5, ListNode(6, ListNode(4)))
    
    sol = Solution()
    result = sol.addTwoNumbers(l1, l2)
    
    print("Result: ", end="")
    while result:
        print(result.val, end=" ")
        result = result.next
    print()

"""
Time Complexity: O(max(m, n)) where m and n are lengths of the lists
Space Complexity: O(max(m, n)) for the result list
"""
