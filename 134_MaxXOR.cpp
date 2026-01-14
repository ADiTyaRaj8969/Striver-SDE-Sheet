/*
Problem: Maximum XOR of Two Numbers
Description: Find maximum XOR of any two numbers in array.

Approach: Build trie of binary representations. For each number, try to find
          complement (opposite bits) to maximize XOR.
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[2];  // 0 and 1
    
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie {
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* node = root;
        
        // Process from MSB to LSB (31 to 0)
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            
            node = node->children[bit];
        }
    }
    
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            
            // Try to go opposite direction for max XOR
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
    
    // Insert all numbers
    for (int num : nums) {
        trie.insert(num);
    }
    
    // Find max XOR for each number
    int maxXOR = 0;
    for (int num : nums) {
        maxXOR = max(maxXOR, trie.findMaxXOR(num));
    }
    
    return maxXOR;
}

int main() {
    vector<int> nums1 = {3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR: " << findMaximumXOR(nums1) << endl;  // Output: 28
    
    vector<int> nums2 = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    cout << "Maximum XOR: " << findMaximumXOR(nums2) << endl;
    
    return 0;
}

/*
Time Complexity: O(n * 32) = O(n)
Space Complexity: O(n * 32) = O(n)
*/
