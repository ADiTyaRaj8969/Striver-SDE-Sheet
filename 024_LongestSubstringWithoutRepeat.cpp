/*
Problem: Longest Substring Without Repeating Characters
Description: Find the length of the longest substring without repeating characters.

Approach: Use sliding window with hash map to track character positions.
          Adjust window when duplicate found.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (charMap.find(s[right]) != charMap.end() && charMap[s[right]] >= left) {
                left = charMap[s[right]] + 1;
            }
            
            charMap[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << "Longest Substring Without Repeating: " << sol.lengthOfLongestSubstring(s) << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the string
Space Complexity: O(min(n, m)) where m is the character set size
*/
