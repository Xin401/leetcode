from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        res = []
        if root.val not in to_delete:
            res.append(root)
        self.dfs(root, to_delete, res)
        return res

    def dfs(self, node: TreeNode, to_delete: List[int], res: List[TreeNode]):
        if not node:
            return None
        node.left = self.dfs(node.left, to_delete, res)
        node.right = self.dfs(node.right, to_delete, res)
        if node.val in to_delete:
            if node.left:
                res.append(node.left)
            if node.right:
                res.append(node.right)
            return None
        return node
    
if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)
    to_delete = [3,5]
    s = Solution()
    for i in s.delNodes(root, to_delete):
        print(i.val)