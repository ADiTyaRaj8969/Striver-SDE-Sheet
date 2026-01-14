"""
Problem: Longest String with All Prefixes
Description: Find the longest string where all prefixes exist as complete words.

Approach: Build trie with all words. DFS to find longest word where all prefixes
          are complete words (marked as end).
"""

from typing import List

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

def dfs(node: TrieNode, current: str, result: List[str]):
    if len(current) > len(result[0]) or \
       (len(current) == len(result[0]) and current < result[0]):
        result[0] = current
    
    for c in sorted(node.children.keys()):
        if node.children[c].isEnd:
            dfs(node.children[c], current + c, result)

def longestWord(words: List[str]) -> str:
    trie = Trie()
    for word in words:
        trie.insert(word)
    
    result = [""]
    dfs(trie.root, "", result)
    
    return result[0]

def main():
    words1 = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
    print("Longest word:", longestWord(words1))  # Output: apple
    
    words2 = ["abc", "bc", "ab", "qwe"]
    print("Longest word:", longestWord(words2))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n * m) where n is number of words, m is max length
Space Complexity: O(n * m)
"""
