"""
Problem: Implement Trie II (With Count)
Description: Implement trie with insert, countWordsEqualTo, countWordsStartingWith,
             and erase operations.

Approach: Each node stores count of words ending here and count of words passing through.
"""

class TrieNode:
    def __init__(self):
        self.children = {}
        self.wordCount = 0     # Count of words ending at this node
        self.prefixCount = 0   # Count of words passing through this node

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
            node.prefixCount += 1
        node.wordCount += 1
    
    def countWordsEqualTo(self, word: str) -> int:
        node = self.root
        for c in word:
            if c not in node.children:
                return 0
            node = node.children[c]
        return node.wordCount
    
    def countWordsStartingWith(self, prefix: str) -> int:
        node = self.root
        for c in prefix:
            if c not in node.children:
                return 0
            node = node.children[c]
        return node.prefixCount
    
    def erase(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                return
            node = node.children[c]
            node.prefixCount -= 1
        node.wordCount -= 1

def main():
    trie = Trie()
    
    trie.insert("apple")
    trie.insert("apple")
    trie.insert("app")
    
    print(trie.countWordsEqualTo("apple"))        # Output: 2
    print(trie.countWordsStartingWith("app"))     # Output: 3
    
    trie.erase("apple")
    print(trie.countWordsEqualTo("apple"))        # Output: 1
    print(trie.countWordsStartingWith("app"))     # Output: 2

if __name__ == "__main__":
    main()

"""
Time Complexity: O(m) for all operations
Space Complexity: O(alphabet_size * n * m)
"""
