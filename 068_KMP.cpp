/*
Problem: KMP Algorithm (Knuth-Morris-Pratt)
Description: Efficient pattern matching using LPS (Longest Proper Prefix-Suffix) array.

Approach: Build LPS array for pattern, use it to avoid redundant comparisons.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
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

vector<int> KMP(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> result;
    
    vector<int> lps = computeLPS(pattern);
    
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return result;
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    
    vector<int> result = KMP(text, pattern);
    cout << "Pattern found at indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n + m)
Space Complexity: O(m)
*/
