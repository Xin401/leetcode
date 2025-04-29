from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_check = [set() for _ in range(len(board))]
        column_check = [set() for _ in range(len(board))]
        grid_check = [[set() for _ in range(3)] for _ in range(3)]
        for row_idx, row in enumerate(board):
            for col_idx, n in enumerate(row):
                if n != ".":
                    if n in row_check[row_idx] or n in column_check[col_idx] or n in grid_check[row_idx//3][col_idx//3]:
                        return False
                    else:
                        row_check[row_idx].add(n)
                        column_check[col_idx].add(n)
                        grid_check[row_idx//3][col_idx//3].add(n)
        return True

if __name__ == "__main__":
    board = [["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
    print(Solution().isValidSudoku(board=board))