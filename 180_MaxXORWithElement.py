"""
Problem: Maximum XOR With an Element from Array
Description: Find maximum XOR of query with elements <= limit from array.

Approach: Sort queries by limit. Insert elements into trie in sorted order. Query trie for max XOR.
"""

from typing import List

class TrieNode:
    def __init__(self):
        self.children = [None, None]

class Trie:
    def __init__(self):
        self.root = TrieNode()
        self.isEmpty = True
    
    def insert(self, num: int) -> None:
        self.isEmpty = False
        node = self.root
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            if not node.children[bit]:
                node.children[bit] = TrieNode()
            node = node.children[bit]
    
    def findMaxXOR(self, num: int) -> int:
        if self.isEmpty:
            return -1
        
        node = self.root
        maxXOR = 0
        
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            oppositeBit = 1 - bit
            
            if node.children[oppositeBit]:
                maxXOR |= (1 << i)
                node = node.children[oppositeBit]
            else:
                node = node.children[bit]
        
        return maxXOR

def maximizeXor(nums: List[int], queries: List[List[int]]) -> List[int]:
    nums.sort()
    
    q = [(queries[i][1], queries[i][0], i) for i in range(len(queries))]
    q.sort()
    
    result = [0] * len(queries)
    trie = Trie()
    idx = 0
    
    for limit, val, pos in q:
        while idx < len(nums) and nums[idx] <= limit:
            trie.insert(nums[idx])
            idx += 1
        
        result[pos] = trie.findMaxXOR(val)
    
    return result

def main():
    nums = [0, 1, 2, 3, 4]
    queries = [[3, 1], [1, 3], [5, 6]]
    
    result = maximizeXor(nums, queries)
    
    print(f"Results: {result}")
    # Output: [3, 3, 7]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n + q log q + (n + q) * 32)
Space Complexity: O(n * 32)
"""
