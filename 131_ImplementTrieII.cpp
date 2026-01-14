/*
Problem: Implement Trie II (With Count)
Description: Implement trie with insert, countWordsEqualTo, countWordsStartingWith,
             and erase operations.

Approach: Each node stores count of words ending here and count of words passing through.
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int wordCount;     // Count of words ending at this node
    int prefixCount;   // Count of words passing through this node
    
    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        wordCount = 0;
        prefixCount = 0;
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
            node->prefixCount++;
        }
        node->wordCount++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                return 0;
            node = node->children[idx];
        }
        return node->wordCount;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx])
                return 0;
            node = node->children[idx];
        }
        return node->prefixCount;
    }
    
    void erase(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                return;
            node = node->children[idx];
            node->prefixCount--;
        }
        node->wordCount--;
    }
};

int main() {
    Trie trie;
    
    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");
    
    cout << trie.countWordsEqualTo("apple") << endl;        // Output: 2
    cout << trie.countWordsStartingWith("app") << endl;     // Output: 3
    
    trie.erase("apple");
    cout << trie.countWordsEqualTo("apple") << endl;        // Output: 1
    cout << trie.countWordsStartingWith("app") << endl;     // Output: 2
    
    return 0;
}

/*
Time Complexity: O(m) for all operations
Space Complexity: O(alphabet_size * n * m)
*/
