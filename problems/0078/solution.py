from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        path = []
        res = []

        def backtrack(startIndex: int):
            res.append(path[:])

            for i in range(startIndex, len(nums)):
                path.append(nums[i])
                backtrack(i + 1)
                path.pop()

        backtrack(0)
        return res
