"""
Problem: Maximum XOR of Two Numbers
Description: Find maximum XOR of any two numbers in array.

Approach: Build trie of binary representations. For each number, try to find
          complement (opposite bits) to maximize XOR.
"""

from typing import List

class TrieNode:
    def __init__(self):
        self.children = [None, None]  # 0 and 1

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, num: int):
        node = self.root
        
        # Process from MSB to LSB (31 to 0)
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            
            if node.children[bit] is None:
                node.children[bit] = TrieNode()
            
            node = node.children[bit]
    
    def findMaxXOR(self, num: int) -> int:
        node = self.root
        maxXOR = 0
        
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            oppositeBit = 1 - bit
            
            # Try to go opposite direction for max XOR
            if node.children[oppositeBit]:
                maxXOR |= (1 << i)
                node = node.children[oppositeBit]
            else:
                node = node.children[bit]
        
        return maxXOR

def findMaximumXOR(nums: List[int]) -> int:
    trie = Trie()
    
    # Insert all numbers
    for num in nums:
        trie.insert(num)
    
    # Find max XOR for each number
    maxXOR = 0
    for num in nums:
        maxXOR = max(maxXOR, trie.findMaxXOR(num))
    
    return maxXOR

def main():
    nums1 = [3, 10, 5, 25, 2, 8]
    print("Maximum XOR:", findMaximumXOR(nums1))  # Output: 28
    
    nums2 = [14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70]
    print("Maximum XOR:", findMaximumXOR(nums2))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n * 32) = O(n)
Space Complexity: O(n * 32) = O(n)
"""
