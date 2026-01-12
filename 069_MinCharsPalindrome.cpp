/*
Problem: Minimum Characters to Make String Palindrome
Description: Find minimum characters to be inserted at beginning to make
             string a palindrome.

Approach: Use KMP LPS array on string + reverse string to find longest prefix
          that is also suffix.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string s) {
    int n = s.length();
    vector<int> lps(n, 0);
    int len = 0, i = 1;
    
    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int minCharsToMakePalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    string concat = s + "$" + rev;
    vector<int> lps = computeLPS(concat);
    
    return s.length() - lps.back();
}

int main() {
    string s1 = "ABC";
    cout << minCharsToMakePalindrome(s1) << endl;  // Output: 2
    
    string s2 = "AACECAAAA";
    cout << minCharsToMakePalindrome(s2) << endl;  // Output: 2
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
