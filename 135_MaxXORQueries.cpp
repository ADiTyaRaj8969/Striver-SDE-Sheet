/*
Problem: Maximum XOR with Element from Array (Queries)
Description: Answer queries where each query asks for max XOR of given element
             with elements ≤ given limit.

Approach: Sort queries and array. Build trie incrementally with elements ≤ limit.
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[2];
    
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
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }
    
    int findMaxXOR(int num) {
        if (!root->children[0] && !root->children[1])
            return -1;
        
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

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(), nums.end());
    
    // Add index to queries and sort by limit
    vector<tuple<int, int, int>> q;  // {limit, x, originalIndex}
    for (int i = 0; i < queries.size(); i++) {
        q.push_back({queries[i][1], queries[i][0], i});
    }
    sort(q.begin(), q.end());
    
    vector<int> result(queries.size());
    Trie trie;
    int idx = 0;
    
    for (auto [limit, x, originalIndex] : q) {
        // Add all numbers <= limit to trie
        while (idx < nums.size() && nums[idx] <= limit) {
            trie.insert(nums[idx]);
            idx++;
        }
        
        result[originalIndex] = trie.findMaxXOR(x);
    }
    
    return result;
}

int main() {
    vector<int> nums = {0, 1, 2, 3, 4};
    vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};
    
    vector<int> result = maximizeXor(nums, queries);
    
    cout << "Results: ";
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;  // Output: 3 3 7
    
    return 0;
}

/*
Time Complexity: O(n log n + q log q + (n + q) * 32)
Space Complexity: O(n * 32)
*/
