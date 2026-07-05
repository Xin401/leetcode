from typing import List
from collections import deque


class Solution:
    # 抽象圖 BFS
    def abstract_graph_bfs(self, start_node: int, adj: dict) -> int:
        q = deque([start_node])
        visited = set([start_node])
        steps = 0

        while q:
            size = len(q)
            for _ in range(size):
                curr = q.popleft()

                # 判斷是否抵達終點
                # if curr == target: return steps

                for neighbor in adj[curr]:
                    if neighbor not in visited:
                        visited.add(neighbor)  # 加入的當下立刻標記
                        q.append(neighbor)

            steps += 1

        return -1

    # 二維網格 BFS
    def grid_bfs(self, grid: List[List[int]], start_r: int, start_c: int) -> int:
        rows, cols = len(grid), len(grid[0])
        q = deque([(start_r, start_c)])

        # 若能直接修改 grid，可省略 visited set，直接標記 grid[r][c]
        visited = set([(start_r, start_c)])
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        steps = 0

        while q:
            size = len(q)
            for _ in range(size):
                r, c = q.popleft()

                # 判斷是否抵達終點
                # if r == target_r and c == target_c: return steps

                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc

                    # 邊界與合法性檢查
                    if 0 <= nr < rows and 0 <= nc < cols:
                        if (nr, nc) not in visited:  # 加上 grid[nr][nc] == 條件
                            visited.add((nr, nc))  # 立刻標記
                            q.append((nr, nc))

            steps += 1

        return -1
