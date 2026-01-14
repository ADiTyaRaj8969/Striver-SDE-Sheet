/*
Problem: Check for Balanced Parentheses
Description: Check if string has balanced parentheses - (), {}, [].

Approach: Use stack. Push opening brackets. For closing, check if matching opening is on top.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    
    return st.empty();
}

int main() {
    string s1 = "()[]{}";
    cout << s1 << " is " << (isValid(s1) ? "valid" : "invalid") << endl;
    // Output: valid
    
    string s2 = "([)]";
    cout << s2 << " is " << (isValid(s2) ? "valid" : "invalid") << endl;
    // Output: invalid
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
