from typing import List

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        ret = 0
        allSubsets = [[]]
        for num in nums:
            allSubsets += [subset + [num] for subset in allSubsets]
        for element in allSubsets:
            xor = 0
            for num in element:
                xor ^= num
            ret += xor
        return ret
    

if __name__ == '__main__':
    sol = Solution()
    print(sol.subsetXORSum([5,1,6]))