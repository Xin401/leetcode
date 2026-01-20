# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        self.result = 0

        def dfs(node):
            if not node:
                return []
            if not node.left and not node.right:
                return [1]  # 返回葉子節點的深度列表，此時深度為1
            left_depths = dfs(node.left)
            right_depths = dfs(node.right)
            # 檢查左右子樹的葉子節點深度，計算距離
            for l in left_depths:
                for r in right_depths:
                    if l + r <= distance:
                        self.result += 1
            # 更新當前節點下所有葉子節點的深度
            return [depth + 1 for depth in left_depths + right_depths]

        dfs(root)
        return self.result
    
if __name__ == "__main__":
    s = Solution()
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)
    print(s.countPairs(root, 3)) 


