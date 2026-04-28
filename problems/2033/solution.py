from typing import List

class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        if len(grid) == 1 and len(grid[0]) == 1:
            return 0
        rmd: int = grid[0][0] % x
        nums: List[int] = []
        res: int = 0
        for l in grid:
            for n in l:
                if n % x != rmd:
                    return -1
                nums.append(n)
        nums.sort()
        median: int = nums[len(nums)//2]
        for n in nums:
            res += abs(median - n ) // x
        return res