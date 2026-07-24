from typing import List


class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        level2 = [False] * 2049
        level3 = [False] * 2049
        ret = 0

        for n in nums:
            for m in nums:
                level2[n ^ m] = True

        for i in range(len(level2)):
            if not level2[i]:
                continue
            for m in nums:
                if not level3[i ^ m]:
                    level3[i ^ m] = True
                    ret += 1
        return ret
