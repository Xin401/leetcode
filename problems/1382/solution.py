from typing import *
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    nodes = []
    def inorder(self, node: Optional[TreeNode]) -> list:
        if not node:
            return
        self.inorder(node.left)
        self.nodes.append(node)
        self.inorder(node.right)
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.nodes = []
        self.inorder(root)
        root = self.nodes[len(self.nodes)//2]
        def build_tree(arr: list):
            if not arr:
                return None
            r = arr[len(arr)//2]
            r.left = build_tree(arr[:len(arr)//2])
            r.right = build_tree(arr[len(arr)//2+1:])
            return r
        root.left = build_tree(self.nodes[:len(self.nodes)//2])
        root.right = build_tree(self.nodes[len(self.nodes)//2+1:])
        return root
