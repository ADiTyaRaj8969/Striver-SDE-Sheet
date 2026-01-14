/*
Problem: Word Break
Description: Determine if string can be segmented into space-separated sequence
             of dictionary words.

Approach: DP - dp[i] = true if s[0..i-1] can be segmented.
          For each position i, check all substrings ending at i.
*/

#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[n];
}

// Return all possible sentences
void wordBreakHelper(string s, unordered_set<string>& dict, string current, 
                     vector<string>& result, int start) {
    if (start == s.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i < s.size(); i++) {
        string word = s.substr(start, i - start + 1);
        if (dict.count(word)) {
            string newCurrent = current.empty() ? word : current + " " + word;
            wordBreakHelper(s, dict, newCurrent, result, i + 1);
        }
    }
}

vector<string> wordBreakII(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<string> result;
    wordBreakHelper(s, dict, "", result, 0);
    return result;
}

int main() {
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << "Can break: " << (wordBreak(s1, wordDict1) ? "true" : "false") << endl;  // Output: true
    
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << "Can break: " << (wordBreak(s2, wordDict2) ? "true" : "false") << endl;  // Output: true
    
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Can break: " << (wordBreak(s3, wordDict3) ? "true" : "false") << endl;  // Output: false
    
    cout << "\nAll possible sentences:" << endl;
    vector<string> sentences = wordBreakII(s2, wordDict2);
    for (const string& sentence : sentences) {
        cout << sentence << endl;
    }
    
    return 0;
}

/*
Time Complexity: O(n^3) for word break I, O(2^n) for word break II
Space Complexity: O(n)
*/
