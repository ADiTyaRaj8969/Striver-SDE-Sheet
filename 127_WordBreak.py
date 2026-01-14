"""
Problem: Word Break
Description: Determine if string can be segmented into space-separated sequence
             of dictionary words.

Approach: DP - dp[i] = true if s[0..i-1] can be segmented.
          For each position i, check all substrings ending at i.
"""

from typing import List, Set

def wordBreak(s: str, wordDict: List[str]) -> bool:
    n = len(s)
    word_set = set(wordDict)
    dp = [False] * (n + 1)
    dp[0] = True
    
    for i in range(1, n + 1):
        for j in range(i):
            if dp[j] and s[j:i] in word_set:
                dp[i] = True
                break
    
    return dp[n]

# Return all possible sentences
def wordBreakHelper(s: str, word_set: Set[str], current: str, 
                    result: List[str], start: int):
    if start == len(s):
        result.append(current)
        return
    
    for i in range(start, len(s)):
        word = s[start:i+1]
        if word in word_set:
            new_current = word if not current else current + " " + word
            wordBreakHelper(s, word_set, new_current, result, i + 1)

def wordBreakII(s: str, wordDict: List[str]) -> List[str]:
    word_set = set(wordDict)
    result = []
    wordBreakHelper(s, word_set, "", result, 0)
    return result

def main():
    s1 = "leetcode"
    wordDict1 = ["leet", "code"]
    print("Can break:", wordBreak(s1, wordDict1))  # Output: True
    
    s2 = "applepenapple"
    wordDict2 = ["apple", "pen"]
    print("Can break:", wordBreak(s2, wordDict2))  # Output: True
    
    s3 = "catsandog"
    wordDict3 = ["cats", "dog", "sand", "and", "cat"]
    print("Can break:", wordBreak(s3, wordDict3))  # Output: False
    
    print("\nAll possible sentences:")
    sentences = wordBreakII(s2, wordDict2)
    for sentence in sentences:
        print(sentence)

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n^3) for word break I, O(2^n) for word break II
Space Complexity: O(n)
"""
