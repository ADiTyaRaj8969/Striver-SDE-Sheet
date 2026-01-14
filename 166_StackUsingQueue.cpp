/*
Problem: Implement Stack using Queues
Description: Implement stack operations (push, pop, top) using queue(s).

Approach: Use one queue. For push, add element and rotate queue to make new element front.
*/

#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q;
    
public:
    MyStack() {}
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << "Top: " << stack.top() << endl;    // Output: 2
    cout << "Pop: " << stack.pop() << endl;    // Output: 2
    cout << "Empty: " << stack.empty() << endl; // Output: 0
    
    return 0;
}

/*
Time Complexity: push O(n), pop/top/empty O(1)
Space Complexity: O(n)
*/
