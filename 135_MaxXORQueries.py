"""
Problem: Maximum XOR with Element from Array (Queries)
Description: Answer queries where each query asks for max XOR of given element
             with elements ≤ given limit.

Approach: Sort queries and array. Build trie incrementally with elements ≤ limit.
"""

from typing import List

class TrieNode:
    def __init__(self):
        self.children = [None, None]

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, num: int):
        node = self.root
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            if node.children[bit] is None:
                node.children[bit] = TrieNode()
            node = node.children[bit]
    
    def findMaxXOR(self, num: int) -> int:
        if self.root.children[0] is None and self.root.children[1] is None:
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
    
    # Add index to queries and sort by limit
    q = [(queries[i][1], queries[i][0], i) for i in range(len(queries))]
    q.sort()
    
    result = [0] * len(queries)
    trie = Trie()
    idx = 0
    
    for limit, x, originalIndex in q:
        # Add all numbers <= limit to trie
        while idx < len(nums) and nums[idx] <= limit:
            trie.insert(nums[idx])
            idx += 1
        
        result[originalIndex] = trie.findMaxXOR(x)
    
    return result

def main():
    nums = [0, 1, 2, 3, 4]
    queries = [[3, 1], [1, 3], [5, 6]]
    
    result = maximizeXor(nums, queries)
    
    print("Results:", result)  # Output: [3, 3, 7]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n + q log q + (n + q) * 32)
Space Complexity: O(n * 32)
"""
