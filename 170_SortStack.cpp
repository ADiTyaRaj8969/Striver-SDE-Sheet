/*
Problem: Sort a Stack
Description: Sort a stack using recursion without using any other data structures.

Approach: Recursively pop all elements. Insert each element in sorted position.
*/

#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int>& st, int element) {
    if (st.empty() || st.top() < element) {
        st.push(element);
        return;
    }
    
    int top = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(top);
}

void sortStack(stack<int>& st) {
    if (st.empty()) return;
    
    int top = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, top);
}

int main() {
    stack<int> st;
    st.push(5);
    st.push(1);
    st.push(0);
    st.push(2);
    
    sortStack(st);
    
    cout << "Sorted stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    // Output: 5 2 1 0
    
    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n) for recursion
*/
