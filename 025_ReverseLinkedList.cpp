/*
Problem: Reverse a Linked List
Description: Reverse a singly linked list.

Approach: Use three pointers (prev, curr, next) to reverse links iteratively.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    // Recursive approach
    ListNode* reverseListRecursive(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* newHead = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    Solution sol;
    ListNode* reversed = sol.reverseList(head);
    
    cout << "Reversed List: ";
    while (reversed != NULL) {
        cout << reversed->val << " ";
        reversed = reversed->next;
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the number of nodes
Space Complexity: O(1) for iterative, O(n) for recursive (call stack)
*/
