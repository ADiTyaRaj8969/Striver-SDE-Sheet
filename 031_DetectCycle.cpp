/*
Problem: Detect Cycle in Linked List
Description: Check if a linked list has a cycle (loop).

Approach: Use Floyd's Cycle Detection (slow and fast pointers).
          If they meet, there's a cycle.
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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create cycle
    
    Solution sol;
    cout << "Has Cycle: " << (sol.hasCycle(head) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the number of nodes
Space Complexity: O(1)
*/
