from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        dic = {}
        for i in nums:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
        ret = []
        for i in dic:
            if dic[i] == 1:
                ret.append(i)
        return ret
    
if __name__ == "__main__":
    nums = [1,2,1,3,2,5]
    s = Solution()
    print(s.singleNumber(nums)) # [3,5]