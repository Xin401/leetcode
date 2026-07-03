from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        path = []
        res = []

        def backtrack(pathSum, startIndex):
            if pathSum == target:
                res.append(path[:])
            elif pathSum > target:
                return
            for i in range(startIndex, len(candidates)):
                path.append(candidates[i])
                backtrack(pathSum + candidates[i], i)
                path.pop()

        backtrack(0, 0)
        return res
