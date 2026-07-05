from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        res = 0

        def grid_dfs(r: int, c: int):
            if (
                r < 0
                or r >= len(grid)
                or c < 0
                or c >= len(grid[0])
                or grid[r][c] == "0"
            ):
                return
            grid[r][c] = "0"

            for dr, dc in dirs:
                grid_dfs(r + dr, c + dc)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    res += 1
                    grid_dfs(i, j)
        return res
