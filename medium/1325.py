from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def pruneTree(self, root: Optional[TreeNode], target: int):
        if root.left:
            self.pruneTree(root.left, target)
        if root.right:
            self.pruneTree(root.right, target)
        #prune left
        if root.left is not None:
                if root.left.left is None and root.left.right is None and root.left.val == target:
                    root.left = None
        #prune right
        if root.right is not None:
            if root.right.left is None and root.right.right is None and root.right.val == target:
                root.right = None
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        self.pruneTree(root, target)
        if root.left is None and root.right is None and root.val == target:
            return None
        return root
    