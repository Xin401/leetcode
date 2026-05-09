from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        upper = 0
        lower = len(matrix) - 1
        column = 0
        while upper != lower:
            if upper + 1 == lower:
                if matrix[lower][0] <= target:
                    column = lower
                else:
                    column = upper
                break
            mid = (upper + lower) // 2
            print(upper, mid, lower, sep=',')
            if matrix[mid][0] <= target and matrix[mid + 1][0] > target:
                column = mid
                break
            elif matrix[mid][0] >  target:
                lower = mid
            elif matrix[mid + 1][0] <= target:
                upper = mid

        left = 0
        right = len(matrix[0]) - 1
        while left != right:
            if left + 1 == right:
                break
            mid = (left + right) // 2
            if matrix[column][mid] < target:
                left = mid
            elif matrix[column][mid] == target:
                return True
            else:
                right = mid

        if matrix[column][left] == target or matrix[column][right] == target:
            return True
        return False

if __name__ == '__main__':
    print(Solution().searchMatrix([[1],[3],[5]], 5))