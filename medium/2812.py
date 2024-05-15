from typing import List
from collections import deque
import heapq

class Solution:
    def __init__(self) -> None:
        self.directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    def valid(self, x: int, y: int, grid: List[List[int]]) -> bool:
        return 0 <= x < len(grid) and 0 <= y < len(grid[0])
    def bfs(self, grid: List[List[int]], score: List[List[int]], x: int, y: int):
        queue = deque()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    queue.append((i, j))
                    score[i][j] = 0
        while queue:
            x, y = queue.popleft()
            for dx, dy in self.directions:
                nx, ny = x + dx, y + dy
                if self.valid(nx, ny, grid) and score[nx][ny] == -1:
                    score[nx][ny] = score[x][y] + 1
                    queue.append((nx, ny))

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        if grid[0][0]==1 or grid[-1][-1]==1:
            return 0
        n = len(grid)
        score = [[-1 for _ in range(n)] for _ in range(n)]
        visited = [[False for _ in range(n)] for _ in range(n)]
        self.bfs(grid, score, 0, 0) 
        elements = []
        heapq.heappush(elements, (-score[0][0],0,0))
        while elements:
            s, x, y = heapq.heappop(elements)
            if x == n-1 and y == n-1:
                return -s
            for dx, dy in self.directions:
                nx, ny = x + dx, y + dy
                if self.valid(nx, ny, grid) and not visited[nx][ny]:
                    ns = min(-s, score[nx][ny])
                    heapq.heappush(elements, (-ns, nx, ny))
                    visited[nx][ny] = True

        return 0
    
if __name__ == "__main__":
    grid = [[1,0,0],[0,0,0],[0,0,1]]
    # grid = [[0,0,1],[0,0,0],[0,0,0]]
    # grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
    print(Solution().maximumSafenessFactor(grid)) # 2
    