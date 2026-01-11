/*
Problem: Implement Stack using Array
Description: Build a stack data structure using only an array.

Approach: Use array with a top pointer. Push adds element, pop removes from top.
*/

#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;
    
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    
    ~Stack() {
        delete[] arr;
    }
    
    void push(int x) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }
    
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }
    
    int peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }
    
    bool isEmpty() {
        return top < 0;
    }
    
    int size() {
        return top + 1;
    }
};

int main() {
    Stack s(5);
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Stack size: " << s.size() << endl;
    
    return 0;
}

/*
Time Complexity: O(1) for all operations
Space Complexity: O(n) where n is stack capacity
*/
