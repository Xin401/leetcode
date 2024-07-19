from typing import List

class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        res = []
        for i in range(len(matrix)):
            min_val = min(matrix[i])
            min_index = matrix[i].index(min_val)
            max_val = max([matrix[j][min_index] for j in range(len(matrix))])
            if min_val == max_val:
                res.append(min_val)
        return res


if __name__ == "__main__":
    matrix = [[3,7,8],[9,11,13],[15,16,17]]
    s = Solution()
    print(s.luckyNumbers(matrix))  # [15]