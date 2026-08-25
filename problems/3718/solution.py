class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        rec = [False] * 101
        for n in nums:
            rec[n] = True
        ptr = k
        while ptr <= 100:
            if rec[ptr] == False:
                return ptr
            ptr += k

        return ptr
