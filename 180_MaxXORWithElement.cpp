/*
Problem: Maximum XOR With an Element from Array
Description: Find maximum XOR of query with elements <= limit from array.

Approach: Sort queries by limit. Insert elements into trie in sorted order. Query trie for max XOR.
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
        if (!node->children[0] && !node->children[1]) return -1;
        
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
    
    vector<vector<int>> q;
    for (int i = 0; i < queries.size(); i++) {
        q.push_back({queries[i][1], queries[i][0], i});
    }
    sort(q.begin(), q.end());
    
    vector<int> result(queries.size());
    Trie trie;
    int idx = 0;
    
    for (auto& query : q) {
        int limit = query[0], val = query[1], pos = query[2];
        
        while (idx < nums.size() && nums[idx] <= limit) {
            trie.insert(nums[idx++]);
        }
        
        result[pos] = trie.findMaxXOR(val);
    }
    
    return result;
}

int main() {
    vector<int> nums = {0, 1, 2, 3, 4};
    vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};
    
    vector<int> result = maximizeXor(nums, queries);
    
    cout << "Results: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    // Output: 3 3 7
    
    return 0;
}

/*
Time Complexity: O(n log n + q log q + (n + q) * 32)
Space Complexity: O(n * 32)
*/
