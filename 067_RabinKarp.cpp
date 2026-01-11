/*
Problem: Rabin Karp Algorithm
Description: Pattern searching using rolling hash function.

Approach: Use polynomial rolling hash with prime modulo to match pattern.
*/

#include <bits/stdc++.h>
using namespace std;

const int PRIME = 101;
const int MOD = 1e9 + 7;

long long computeHash(string str, int len) {
    long long hash = 0;
    for (int i = 0; i < len; i++) {
        hash = (hash * PRIME + str[i]) % MOD;
    }
    return hash;
}

vector<int> rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> result;
    
    if (m > n) return result;
    
    long long patternHash = computeHash(pattern, m);
    long long textHash = computeHash(text, m);
    
    long long power = 1;
    for (int i = 0; i < m - 1; i++) {
        power = (power * PRIME) % MOD;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            // Verify match
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) result.push_back(i);
        }
        
        if (i < n - m) {
            textHash = ((textHash - text[i] * power) * PRIME + text[i + m]) % MOD;
            if (textHash < 0) textHash += MOD;
        }
    }
    
    return result;
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    
    vector<int> result = rabinKarp(text, pattern);
    cout << "Pattern found at indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n + m) average, O(nm) worst case
Space Complexity: O(1)
*/
