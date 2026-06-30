from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        res = root.val

        def dfsPostOrder(node: Optional[TreeNode]) -> int:
            nonlocal res
            if not node:
                return 0
            left = dfsPostOrder(node.left)
            right = dfsPostOrder(node.right)
            M = node.val + (left if left > 0 else 0) + (right if right > 0 else 0)
            res = max(res, M)
            return max(left, max(right, 0)) + node.val

        dfsPostOrder(root)
        return res
