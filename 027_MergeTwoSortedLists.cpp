/*
Problem: Merge Two Sorted Linked Lists
Description: Merge two sorted linked lists into one sorted list.

Approach: Use dummy node and merge by comparing values.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = (l1 != NULL) ? l1 : l2;
        
        return dummy.next;
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    
    Solution sol;
    ListNode* merged = sol.mergeTwoLists(l1, l2);
    
    cout << "Merged List: ";
    while (merged != NULL) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(m + n) where m and n are the lengths of the two lists
Space Complexity: O(1)
*/
