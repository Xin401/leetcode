from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        res = []

        def dfsInOrder(node):
            if not node:
                return
            dfsInOrder(node.left)
            res.append(node.val)
            dfsInOrder(node.right)

        dfsInOrder(root)
        for i in range(len(res) - 1):
            if res[i] >= res[i + 1]:
                return False
        return True
