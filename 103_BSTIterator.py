"""
Problem: BST Iterator
Description: Implement iterator for BST with next() and hasNext() methods.

Approach: Use stack to perform iterative inorder traversal.
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BSTIterator:
    def __init__(self, root: Optional[TreeNode]):
        self.stack = []
        self._push_all(root)
    
    def _push_all(self, node: Optional[TreeNode]):
        while node:
            self.stack.append(node)
            node = node.left
    
    def next(self) -> int:
        node = self.stack.pop()
        self._push_all(node.right)
        return node.val
    
    def hasNext(self) -> bool:
        return len(self.stack) > 0

def main():
    root = TreeNode(7)
    root.left = TreeNode(3)
    root.right = TreeNode(15)
    root.right.left = TreeNode(9)
    root.right.right = TreeNode(20)
    
    iterator = BSTIterator(root)
    print(iterator.next())     # Output: 3
    print(iterator.next())     # Output: 7
    print(iterator.hasNext())  # Output: True
    print(iterator.next())     # Output: 9

if __name__ == "__main__":
    main()

"""
Time Complexity: O(1) average for next()
Space Complexity: O(h)
"""
