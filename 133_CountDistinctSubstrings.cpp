/*
Problem: Count Distinct Substrings
Description: Count number of distinct substrings of a string.

Approach: Insert all suffixes into trie. Each node represents a unique substring.
          Count total nodes in trie.
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    
    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

int countDistinctSubstrings(string s) {
    TrieNode* root = new TrieNode();
    int count = 0;  // Empty string
    
    // Insert all suffixes
    for (int i = 0; i < s.size(); i++) {
        TrieNode* node = root;
        
        for (int j = i; j < s.size(); j++) {
            int idx = s[j] - 'a';
            
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
                count++;  // New unique substring
            }
            
            node = node->children[idx];
        }
    }
    
    return count + 1;  // +1 for empty string
}

// Alternative: Using set
int countDistinctSubstringsSet(string s) {
    unordered_set<string> uniqueSubstrings;
    
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            uniqueSubstrings.insert(s.substr(i, j - i + 1));
        }
    }
    
    return uniqueSubstrings.size() + 1;  // +1 for empty string
}

int main() {
    string s1 = "abab";
    cout << "Distinct substrings (Trie): " << countDistinctSubstrings(s1) << endl;  // Output: 8
    cout << "Distinct substrings (Set): " << countDistinctSubstringsSet(s1) << endl;
    
    string s2 = "abc";
    cout << "Distinct substrings: " << countDistinctSubstrings(s2) << endl;  // Output: 7
    
    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/
