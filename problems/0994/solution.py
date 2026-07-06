from typing import List
from collections import deque


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        rows, cols = len(grid), len(grid[0])
        q = deque([])
        steps = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    q.append((i, j))
                    steps = -1
        while q:
            size = len(q)
            for _ in range(size):
                r, c = q.popleft()
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols:
                        if grid[nr][nc] == 1:
                            q.append((nr, nc))
                            grid[nr][nc] = 2
            steps += 1

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    return -1

        return steps
