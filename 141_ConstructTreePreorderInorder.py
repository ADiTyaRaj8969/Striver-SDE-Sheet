"""
Problem: Construct Binary Tree from Preorder and Inorder
Description: Build binary tree from preorder and inorder traversal arrays.

Approach: First element of preorder is root. Find root in inorder to split
          into left and right subtrees. Recursively build left and right.
"""

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildTreeHelper(preorder: List[int], preStart: int, preEnd: int,
                    inorder: List[int], inStart: int, inEnd: int,
                    inMap: dict) -> Optional[TreeNode]:
    if preStart > preEnd or inStart > inEnd:
        return None
    
    rootVal = preorder[preStart]
    root = TreeNode(rootVal)
    
    inRoot = inMap[rootVal]
    numsLeft = inRoot - inStart
    
    root.left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                inorder, inStart, inRoot - 1, inMap)
    root.right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                 inorder, inRoot + 1, inEnd, inMap)
    
    return root

def buildTree(preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
    inMap = {val: i for i, val in enumerate(inorder)}
    
    return buildTreeHelper(preorder, 0, len(preorder) - 1,
                          inorder, 0, len(inorder) - 1, inMap)

def printInorder(root: TreeNode):
    if not root:
        return
    printInorder(root.left)
    print(root.val, end=" ")
    printInorder(root.right)

def main():
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]
    
    root = buildTree(preorder, inorder)
    
    print("Inorder traversal:", end=" ")
    printInorder(root)
    print()

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
