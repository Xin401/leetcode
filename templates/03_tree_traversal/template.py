"""
Time Complexity：O(N)
Space Complexity：
- DFS: O(H)，H 為樹高
- BFS: O(W)，W 為樹的最大寬度
"""

from typing import List, Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def dfs_preorder(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        def dfs(node):
            if not node:
                return
            res.append(node.val)  # 根
            dfs(node.left)  # 左
            dfs(node.right)  # 右

        dfs(root)
        return res

    def dfs_inorder(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        def dfs(node):
            if not node:
                return
            dfs(node.left)  # 左
            res.append(node.val)  # 根
            dfs(node.right)  # 右

        dfs(root)
        return res

    def dfs_postorder(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        def dfs(node):
            if not node:
                return
            dfs(node.left)  # 左
            dfs(node.right)  # 右
            res.append(node.val)  # 根

        dfs(root)
        return res

    def bfs_level_order(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        res = []
        q = deque([root])

        while q:
            level_size = len(q)  # 1. 鎖定當層的節點數量
            level_vals = []

            for _ in range(level_size):
                node = q.popleft()
                level_vals.append(node.val)

                # 2. 將下一層的子節點排入佇列
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            res.append(level_vals)

        return res
