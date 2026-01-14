"""
Problem: Count Distinct Substrings
Description: Count number of distinct substrings of a string.

Approach: Insert all suffixes into trie. Each node represents a unique substring.
          Count total nodes in trie.
"""

class TrieNode:
    def __init__(self):
        self.children = {}

def countDistinctSubstrings(s: str) -> int:
    root = TrieNode()
    count = 0  # Empty string
    
    # Insert all suffixes
    for i in range(len(s)):
        node = root
        
        for j in range(i, len(s)):
            if s[j] not in node.children:
                node.children[s[j]] = TrieNode()
                count += 1  # New unique substring
            
            node = node.children[s[j]]
    
    return count + 1  # +1 for empty string

# Alternative: Using set
def countDistinctSubstringsSet(s: str) -> int:
    uniqueSubstrings = set()
    
    for i in range(len(s)):
        for j in range(i, len(s)):
            uniqueSubstrings.add(s[i:j+1])
    
    return len(uniqueSubstrings) + 1  # +1 for empty string

def main():
    s1 = "abab"
    print("Distinct substrings (Trie):", countDistinctSubstrings(s1))  # Output: 8
    print("Distinct substrings (Set):", countDistinctSubstringsSet(s1))
    
    s2 = "abc"
    print("Distinct substrings:", countDistinctSubstrings(s2))  # Output: 7

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n^2)
Space Complexity: O(n^2)
"""
