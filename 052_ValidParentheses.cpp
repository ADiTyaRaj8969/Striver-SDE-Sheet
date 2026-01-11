/*
Problem: Valid Parentheses (Balanced Parentheses)
Description: Check if a string of parentheses (), {}, [] is valid and balanced.

Approach: Use stack. Push opening brackets, pop and match with closing brackets.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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
};

int main() {
    Solution sol;
    string s = "()[]{}";
    
    cout << "Is Valid: " << (sol.isValid(s) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of string
Space Complexity: O(n) for the stack
*/
