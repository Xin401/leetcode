from typing import List


class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        cnt = [0] * 51
        ret = -1
        for i in range(len(nums) - k + 1):
            has = [False] * 51
            for j in range(i, i + k):
                if not has[nums[j]]:
                    has[nums[j]] = True
                    cnt[nums[j]] += 1
        for i in range(51):
            if cnt[i] == 1:
                ret = i
        return ret
