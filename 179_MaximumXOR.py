"""
Problem: Maximum XOR of Two Numbers
Description: Find maximum XOR of any two numbers in array.

Approach: Use Trie for bits. Insert all numbers. For each number, find max XOR by traversing trie greedily.
"""

from typing import List, Optional

class TrieNode:
    def __init__(self):
        self.children = [None, None]

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, num: int) -> None:
        node = self.root
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            if not node.children[bit]:
                node.children[bit] = TrieNode()
            node = node.children[bit]
    
    def findMaxXOR(self, num: int) -> int:
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

def findMaximumXOR(nums: List[int]) -> int:
    trie = Trie()
    for num in nums:
        trie.insert(num)
    
    maxXOR = 0
    for num in nums:
        maxXOR = max(maxXOR, trie.findMaxXOR(num))
    
    return maxXOR

def main():
    nums = [3, 10, 5, 25, 2, 8]
    
    print(f"Maximum XOR: {findMaximumXOR(nums)}")
    # Output: 28 (5 XOR 25)

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n * 32)
Space Complexity: O(n * 32)
"""
