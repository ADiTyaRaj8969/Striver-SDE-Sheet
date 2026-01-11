/*
Problem: Longest Common Prefix
Description: Find the longest common prefix string amongst an array of strings.

Approach: Compare characters at each position across all strings.
*/

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    
    string prefix = strs[0];
    
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";
        }
    }
    
    return prefix;
}

int main() {
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs1) << endl;  // Output: "fl"
    
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs2) << endl;  // Output: ""
    
    return 0;
}

/*
Time Complexity: O(n * m) where n is number of strings, m is length of shortest string
Space Complexity: O(1)
*/
