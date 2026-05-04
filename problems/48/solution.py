from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        mid = m // 2
        for i in range(m):
            for j in range(m):
                if i == j: break
                tmp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = tmp
        for i in range(m):
            for j in range(m):
                if j == mid: break
                tmp = matrix[i][j]
                matrix[i][j] = matrix[i][m-1-j]
                matrix[i][m-1-j] = tmp