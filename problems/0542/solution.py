from typing import List
from collections import deque


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows, cols = len(mat), len(mat[0])
        q = deque([])
        visited = set([])
        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 0:
                    q.append((i, j))
                    visited.add((i, j))
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        distance = 0
        while q:
            distance += 1
            size = len(q)
            for _ in range(size):
                r, c = q.popleft()
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols:
                        if (nr, nc) not in visited:
                            q.append((nr, nc))
                            visited.add((nr, nc))
                            mat[nr][nc] = distance
        return mat
