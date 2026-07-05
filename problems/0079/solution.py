from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        res: bool = False

        def grid_dfs(r: int, c: int, current_index: int):
            nonlocal res
            if (
                r < 0
                or r >= len(board)
                or c < 0
                or c >= len(board[0])
                or board == "."
                or res
            ):
                return
            dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
            tmp = board[r][c]
            if tmp == word[current_index]:
                if current_index == len(word) - 1:
                    res = True
                    return
                board[r][c] = "."
                for dr, dc in dirs:
                    grid_dfs(r + dr, c + dc, current_index + 1)
                board[r][c] = tmp

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    grid_dfs(i, j, 0)
                if res:
                    return res
        return res
