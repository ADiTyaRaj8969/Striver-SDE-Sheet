/*
Problem: Minimum Window Substring
Description: Find smallest substring of s that contains all characters of t.

Approach: Two pointers with sliding window. Expand right, contract left when valid.
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> required, window;
    
    for (char c : t) required[c]++;
    
    int left = 0, right = 0;
    int formed = 0, needed = required.size();
    int minLen = INT_MAX, minStart = 0;
    
    while (right < s.length()) {
        char c = s[right];
        window[c]++;
        
        if (required.count(c) && window[c] == required[c]) {
            formed++;
        }
        
        while (formed == needed && left <= right) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }
            
            char leftChar = s[left];
            window[leftChar]--;
            if (required.count(leftChar) && window[leftChar] < required[leftChar]) {
                formed--;
            }
            left++;
        }
        
        right++;
    }
    
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    
    cout << "Minimum window: " << minWindow(s, t) << endl;
    // Output: BANC
    
    return 0;
}

/*
Time Complexity: O(|s| + |t|)
Space Complexity: O(|s| + |t|)
*/
