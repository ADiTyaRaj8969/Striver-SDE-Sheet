"""
Problem: Construct Binary Tree from Postorder and Inorder
Description: Build binary tree from postorder and inorder traversal arrays.

Approach: Last element of postorder is root. Find root in inorder to split
          into left and right subtrees. Recursively build right then left.
"""

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildTreeHelper(postorder: List[int], postStart: int, postEnd: int,
                    inorder: List[int], inStart: int, inEnd: int,
                    inMap: dict) -> Optional[TreeNode]:
    if postStart > postEnd or inStart > inEnd:
        return None
    
    rootVal = postorder[postEnd]
    root = TreeNode(rootVal)
    
    inRoot = inMap[rootVal]
    numsLeft = inRoot - inStart
    
    root.left = buildTreeHelper(postorder, postStart, postStart + numsLeft - 1,
                                inorder, inStart, inRoot - 1, inMap)
    root.right = buildTreeHelper(postorder, postStart + numsLeft, postEnd - 1,
                                 inorder, inRoot + 1, inEnd, inMap)
    
    return root

def buildTree(inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
    inMap = {val: i for i, val in enumerate(inorder)}
    
    return buildTreeHelper(postorder, 0, len(postorder) - 1,
                          inorder, 0, len(inorder) - 1, inMap)

def printInorder(root: TreeNode):
    if not root:
        return
    printInorder(root.left)
    print(root.val, end=" ")
    printInorder(root.right)

def main():
    inorder = [9, 3, 15, 20, 7]
    postorder = [9, 15, 7, 20, 3]
    
    root = buildTree(inorder, postorder)
    
    print("Inorder traversal:", end=" ")
    printInorder(root)
    print()

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
