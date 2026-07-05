from typing import List
from collections import deque


class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] == 1:
            return -1
        rows, cols = len(grid), len(grid[0])
        q = deque([(0, 0)])
        grid[0][0] = -1
        dirs = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
        steps = 1
        while q:
            size = len(q)
            for _ in range(size):
                r, c = q.popleft()
                if r == rows - 1 and c == cols - 1:
                    return steps
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols:
                        if grid[nr][nc] == 0:
                            grid[nr][nc] = -1
                            q.append((nr, nc))
            steps += 1
        return -1
