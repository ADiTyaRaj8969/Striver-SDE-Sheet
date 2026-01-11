/*
Problem: Add Two Numbers as Linked List
Description: Add two numbers represented by linked lists where digits are stored in reverse order.

Approach: Traverse both lists, add corresponding digits with carry.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;
        
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;
            
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        
        return dummy.next;
    }
};

int main() {
    // 342 + 465 = 807
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    
    cout << "Result: ";
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(max(m, n)) where m and n are lengths of the lists
Space Complexity: O(max(m, n)) for the result list
*/
