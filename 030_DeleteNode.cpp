/*
Problem: Delete a Given Node
Description: Delete a node from a linked list given only a pointer to that node.
             (The node is not the tail node)

Approach: Copy the value from the next node and delete the next node.
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
    void deleteNode(ListNode* node) {
        // Copy value from next node
        node->val = node->next->val;
        
        // Delete next node
        ListNode* toDelete = node->next;
        node->next = node->next->next;
        delete toDelete;
    }
};

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    
    Solution sol;
    sol.deleteNode(head->next); // Delete node with value 5
    
    cout << "List after deletion: ";
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(1)
Space Complexity: O(1)
*/
