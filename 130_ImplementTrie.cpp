/*
Problem: Implement Trie (Prefix Tree)
Description: Implement a trie with insert, search, and startsWith operations.

Approach: Each node contains 26 children (for 'a'-'z') and a flag for end of word.
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEnd = false;
    }
};

class Trie {
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    Trie trie;
    
    trie.insert("apple");
    cout << trie.search("apple") << endl;    // Output: 1 (true)
    cout << trie.search("app") << endl;      // Output: 0 (false)
    cout << trie.startsWith("app") << endl;  // Output: 1 (true)
    trie.insert("app");
    cout << trie.search("app") << endl;      // Output: 1 (true)
    
    return 0;
}

/*
Time Complexity: O(m) for all operations where m is length of word
Space Complexity: O(alphabet_size * n * m) where n is number of words
*/
