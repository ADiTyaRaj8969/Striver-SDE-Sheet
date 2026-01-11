/*
Problem: Min Stack
Description: Design a stack that supports push, pop, top, and retrieving
             the minimum element in constant time.

Approach: Use two stacks - one for elements, one for tracking minimums.
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;
    
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack minStack;
    
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;  // Output: -3
    minStack.pop();
    cout << minStack.top() << endl;     // Output: 0
    cout << minStack.getMin() << endl;  // Output: -2
    
    return 0;
}

/*
Time Complexity: O(1) for all operations
Space Complexity: O(n)
*/
