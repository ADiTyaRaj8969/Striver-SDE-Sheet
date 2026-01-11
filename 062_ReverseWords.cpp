/*
Problem: Reverse Words in a String
Description: Reverse the order of words in a string.

Approach: Use two pointers to identify words and build result in reverse.
*/

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string result = "";
    int i = 0, n = s.length();
    
    while (i < n) {
        // Skip spaces
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;
        
        // Get word
        int j = i;
        while (j < n && s[j] != ' ') j++;
        string word = s.substr(i, j - i);
        
        // Add to result
        if (result.length() == 0) {
            result = word;
        } else {
            result = word + " " + result;
        }
        
        i = j + 1;
    }
    
    return result;
}

int main() {
    string s1 = "the sky is blue";
    cout << reverseWords(s1) << endl;  // Output: "blue is sky the"
    
    string s2 = "  hello world  ";
    cout << reverseWords(s2) << endl;  // Output: "world hello"
    
    string s3 = "a good   example";
    cout << reverseWords(s3) << endl;  // Output: "example good a"
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
