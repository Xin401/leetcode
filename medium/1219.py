from typing import List

# dfs + backtracking

class Solution:
    def dfs(self, grid: List[List[int]], i: int, j: int) -> int:
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == 0:
            return 0
        tmp = grid[i][j]
        grid[i][j] = 0
        up = self.dfs(grid, i-1, j)
        down = self.dfs(grid, i+1, j)
        left = self.dfs(grid, i, j-1)
        right = self.dfs(grid, i, j+1)
        grid[i][j] = tmp
        return max(up, down, left, right) + tmp
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        ret = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != 0:
                    ret = max(self.dfs(grid, i, j), ret)
        return ret

if __name__ == '__main__':
    grid = [[0,6,0],[5,8,7],[0,9,0]]
    s = Solution()
    print(s.getMaximumGold(grid)) # 24
    grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
    print(s.getMaximumGold(grid)) # 28
    grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]