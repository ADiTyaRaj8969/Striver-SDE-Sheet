/*
Problem: Longest String with All Prefixes
Description: Find the longest string where all prefixes exist as complete words.

Approach: Build trie with all words. DFS to find longest word where all prefixes
          are complete words (marked as end).
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
public:
    TrieNode* root;
    
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
};

void dfs(TrieNode* node, string current, string& result) {
    if (current.size() > result.size() || 
        (current.size() == result.size() && current < result)) {
        result = current;
    }
    
    for (int i = 0; i < 26; i++) {
        if (node->children[i] && node->children[i]->isEnd) {
            current.push_back('a' + i);
            dfs(node->children[i], current, result);
            current.pop_back();
        }
    }
}

string longestWord(vector<string>& words) {
    Trie trie;
    for (const string& word : words) {
        trie.insert(word);
    }
    
    string result = "";
    dfs(trie.root, "", result);
    
    return result;
}

int main() {
    vector<string> words1 = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << "Longest word: " << longestWord(words1) << endl;  // Output: apple
    
    vector<string> words2 = {"abc", "bc", "ab", "qwe"};
    cout << "Longest word: " << longestWord(words2) << endl;
    
    return 0;
}

/*
Time Complexity: O(n * m) where n is number of words, m is max length
Space Complexity: O(n * m)
*/
