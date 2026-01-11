/*
Problem: String to Integer (atoi)
Description: Implement atoi which converts a string to an integer.

Approach: Handle whitespace, sign, overflow, and invalid characters.
*/

#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.length();
    
    // Skip whitespace
    while (i < n && s[i] == ' ') i++;
    
    // Check sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Convert digits
    long result = 0;
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        
        // Check overflow
        if (sign == 1 && result > INT_MAX) return INT_MAX;
        if (sign == -1 && result > INT_MAX) return INT_MIN;
        
        i++;
    }
    
    return sign * result;
}

int main() {
    cout << myAtoi("42") << endl;           // Output: 42
    cout << myAtoi("   -42") << endl;       // Output: -42
    cout << myAtoi("4193 with words") << endl; // Output: 4193
    cout << myAtoi("words and 987") << endl;   // Output: 0
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
