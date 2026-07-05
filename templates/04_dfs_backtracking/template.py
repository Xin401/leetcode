from typing import List


class Solution:
    def backtrack_template(self, nums: List[int]) -> List[List[int]]:
        used = [False] * len(nums)
        path = []
        res = []

        def backtrack():
            # 1. 終止條件
            if len(path) == len(nums):
                res.append(path[:])  # 必須用 [:] 做淺拷貝
                return

            for i in range(len(nums)):
                if used[i]:
                    continue

                # A. 做選擇
                used[i] = True
                path.append(nums[i])

                # B. 遞迴
                backtrack()

                # C. 撤銷選擇
                path.pop()
                used[i] = False

        backtrack()
        return res

    # 2D

    def grid_dfs_template(self, grid: List[List[str]], r: int, c: int):
        # 1. 越界與條件檢查
        if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or grid[r][c] == "0":
            return

        # 2. 標記已訪問
        grid[r][c] = "0"

        # 3. 往四個方向延伸
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        for dr, dc in dirs:
            self.grid_dfs_template(grid, r + dr, c + dc)
