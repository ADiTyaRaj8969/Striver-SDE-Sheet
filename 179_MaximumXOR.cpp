/*
Problem: Maximum XOR of Two Numbers
Description: Find maximum XOR of any two numbers in array.

Approach: Use Trie for bits. Insert all numbers. For each number, find max XOR by traversing trie greedily.
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[2];
    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            
            if (node->children[oppositeBit]) {
                maxXOR |= (1 << i);
                node = node->children[oppositeBit];
            } else {
                node = node->children[bit];
            }
        }
        
        return maxXOR;
    }
};

int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    for (int num : nums) {
        trie.insert(num);
    }
    
    int maxXOR = 0;
    for (int num : nums) {
        maxXOR = max(maxXOR, trie.findMaxXOR(num));
    }
    
    return maxXOR;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    
    cout << "Maximum XOR: " << findMaximumXOR(nums) << endl;
    // Output: 28 (5 XOR 25)
    
    return 0;
}

/*
Time Complexity: O(n * 32)
Space Complexity: O(n * 32)
*/
