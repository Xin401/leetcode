from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        store = set(nums)
        result = 0
        for n in store:
            if n - 1 not in store:
                length = 1
                while n + length in store:
                    length += 1
                result = max(result, length)
        return result


    
if __name__ == "__main__":
    nums = [9,1,4,7,3,-1,0,5,8,-1,6]
    print(Solution().longestConsecutive(nums=nums))

