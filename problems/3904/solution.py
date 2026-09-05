class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        preMax = [0] * len(nums)
        suMin = [0] * len(nums)
        M = nums[0]
        m = nums[-1]
        for i in range(len(nums)):
            M = max(M, nums[i])
            preMax[i] = M
            m = min(m, nums[len(nums) - 1 - i])
            suMin[len(nums) - 1 - i] = m
        for i in range(len(nums)):
            if preMax[i] - suMin[i] <= k:
                return i
        return -1
