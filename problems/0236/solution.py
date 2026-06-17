# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        def dfsPostOrder(node: "TreeNode", p: "TreeNode", q: "TreeNode"):
            if not node:
                return None
            left = dfsPostOrder(node.left, p, q)
            right = dfsPostOrder(node.right, p, q)
            if node.val == p.val or node.val == q.val:
                return node

            if left and right:
                return node
            return left if left else right

        return dfsPostOrder(root, p, q)
