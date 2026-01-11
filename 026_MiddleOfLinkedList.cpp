/*
Problem: Find Middle of Linked List
Description: Find the middle node of a linked list. If there are two middle nodes,
             return the second middle node.

Approach: Use slow and fast pointer (tortoise and hare).
          When fast reaches end, slow is at middle.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    Solution sol;
    ListNode* middle = sol.middleNode(head);
    
    cout << "Middle Node: " << middle->val << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the number of nodes
Space Complexity: O(1)
*/
