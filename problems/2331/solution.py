from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def evaluateChildren(self,root: Optional[TreeNode]) -> bool:
        if root.left is None:
            return bool(root.val)
        elif root.val == 2:
            return (self.evaluateTree(root.left) or self.evaluateTree(root.right))
        else:
            return (self.evaluateTree(root.left) and self.evaluateTree(root.right))    
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        ret = self.evaluateChildren(root)
        return ret
    
if __name__ == '__main__':
    sol = Solution()
    root = TreeNode(2,TreeNode(0,TreeNode(0),TreeNode(0)),TreeNode(0,TreeNode(0),TreeNode(0)))
    print(sol.evaluateTree(root))
        