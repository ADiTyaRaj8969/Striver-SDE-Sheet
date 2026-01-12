/*
Problem: Check for Anagrams
Description: Check if two strings are anagrams of each other.

Approach: Count character frequencies and compare.
*/

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    
    unordered_map<char, int> freq;
    
    for (char c : s) {
        freq[c]++;
    }
    
    for (char c : t) {
        freq[c]--;
        if (freq[c] < 0) return false;
    }
    
    return true;
}

int main() {
    cout << isAnagram("anagram", "nagaram") << endl;  // Output: 1 (true)
    cout << isAnagram("rat", "car") << endl;          // Output: 0 (false)
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1) - at most 26 characters
*/
