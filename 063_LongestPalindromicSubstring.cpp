/*
Problem: Longest Palindromic Substring
Description: Find the longest palindromic substring in a string.

Approach: Expand around center for each position (odd and even length palindromes).
*/

#include <bits/stdc++.h>
using namespace std;

string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.length() < 1) return "";
    
    string longest = "";
    
    for (int i = 0; i < s.length(); i++) {
        // Odd length palindromes
        string odd = expandAroundCenter(s, i, i);
        if (odd.length() > longest.length()) {
            longest = odd;
        }
        
        // Even length palindromes
        string even = expandAroundCenter(s, i, i + 1);
        if (even.length() > longest.length()) {
            longest = even;
        }
    }
    
    return longest;
}

int main() {
    string s1 = "babad";
    cout << longestPalindrome(s1) << endl;  // Output: "bab" or "aba"
    
    string s2 = "cbbd";
    cout << longestPalindrome(s2) << endl;  // Output: "bb"
    
    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
