from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #First solution
        # myDict = {}
        # diffs = [target - n for n in nums]
        # for idx,n in enumerate(nums):
        #     myDict[n] = idx
        # for idx, diff in enumerate(diffs):
        #     if diff in myDict and myDict[diff] != idx:
        #         return [idx,myDict[diff]]

        #Second solution
        myDict = {}
        for idx, n in enumerate(nums):
            diff = target - n
            if diff in myDict:
                return [myDict[diff], idx]
            myDict[n] = idx

if __name__ == "__main__":
    print(Solution().twoSum([3,2,4],6))