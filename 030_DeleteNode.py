"""
Problem: Delete a Given Node
Description: Delete a node from a linked list given only a pointer to that node.
             (The node is not the tail node)

Approach: Copy the value from the next node and delete the next node.
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteNode(self, node: ListNode) -> None:
        # Copy value from next node
        node.val = node.next.val
        
        # Delete next node
        node.next = node.next.next

if __name__ == "__main__":
    head = ListNode(4, ListNode(5, ListNode(1, ListNode(9))))
    
    sol = Solution()
    sol.deleteNode(head.next)  # Delete node with value 5
    
    print("List after deletion: ", end="")
    while head:
        print(head.val, end=" ")
        head = head.next
    print()

"""
Time Complexity: O(1)
Space Complexity: O(1)
"""
