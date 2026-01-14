"""
Problem: Implement Trie (Prefix Tree)
Description: Implement a trie with insert, search, and startsWith operations.

Approach: Each node contains 26 children (for 'a'-'z') and a flag for end of word.
"""

class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.isEnd = True
    
    def search(self, word: str) -> bool:
        node = self.root
        for c in word:
            if c not in node.children:
                return False
            node = node.children[c]
        return node.isEnd
    
    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for c in prefix:
            if c not in node.children:
                return False
            node = node.children[c]
        return True

def main():
    trie = Trie()
    
    trie.insert("apple")
    print(trie.search("apple"))    # Output: True
    print(trie.search("app"))      # Output: False
    print(trie.startsWith("app"))  # Output: True
    trie.insert("app")
    print(trie.search("app"))      # Output: True

if __name__ == "__main__":
    main()

"""
Time Complexity: O(m) for all operations where m is length of word
Space Complexity: O(alphabet_size * n * m) where n is number of words
"""
