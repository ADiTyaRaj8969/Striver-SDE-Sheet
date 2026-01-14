/*
Problem: Implement Queue using Stacks
Description: Implement queue operations (enqueue, dequeue, peek) using stack(s).

Approach: Use two stacks. Input stack for enqueue. Transfer to output stack for dequeue/peek when needed.
*/

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> input, output;
    
    void transfer() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }
    
public:
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        transfer();
        int front = output.top();
        output.pop();
        return front;
    }
    
    int peek() {
        transfer();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    cout << "Peek: " << queue.peek() << endl;   // Output: 1
    cout << "Pop: " << queue.pop() << endl;     // Output: 1
    cout << "Empty: " << queue.empty() << endl; // Output: 0
    
    return 0;
}

/*
Time Complexity: push O(1), pop/peek O(1) amortized
Space Complexity: O(n)
*/
