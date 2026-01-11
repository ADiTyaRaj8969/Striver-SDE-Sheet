/*
Problem: Remove N-th Node from End of List
Description: Remove the N-th node from the end of a linked list.

Approach: Use two pointers with N gap between them. When fast reaches end,
          slow is at the node before the one to delete.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both until fast reaches end
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove the node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        return dummy.next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    Solution sol;
    head = sol.removeNthFromEnd(head, 2);
    
    cout << "List after removal: ";
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the number of nodes
Space Complexity: O(1)
*/
