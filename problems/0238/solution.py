from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # prefix = [1]
        # suffix = [1]
        # result = []
        # for idx, n in enumerate(nums):
        #     if idx == len(nums) - 1:
        #         break
        #     prefix.append(prefix[idx] * n)
        #     suffix.append(suffix[idx])
        # for idx, n in enumerate(reversed(nums)):
        #     if idx == len(nums) - 1:
        #         break
        #     suffix.append(suffix[idx] * n)
        # for idx in range(len(prefix)):
        #     result.append(prefix[idx]*suffix[len(suffix) - 1 -idx])
        # return result
        result = [1 for _ in range(len(nums))]
        prefix_production = 1
        suffix_production = 1
        for i in range(1, len(nums)):
            prefix_production *= nums[i - 1]
            suffix_production *= nums[len(nums) - i]
            result[i] *= prefix_production
            result[len(nums) - 1 - i] *= suffix_production
        return result


if __name__ == "__main__":
    nums = [1,2,3,4]
    # nums = [-1,1,0,-3,3]
    print(Solution().productExceptSelf(nums=nums))
