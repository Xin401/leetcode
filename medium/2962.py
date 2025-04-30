from typing import List

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        # target = max(nums)
        # length = len(nums)
        # print(target)
        # target_idx = [-1]
        # result = 0
        # for idx, n in enumerate(nums):
        #     if n == target:
        #         target_idx.append(idx)
        # if len(target_idx) <= k:
        #     return 0
        # print(target_idx)
        # for i in range(1,len(target_idx)-k+1):
        #     print(target_idx[i] - target_idx[i-1],',',length - target_idx[i+k-1])
        #     result +=(target_idx[i] - target_idx[i-1]) * (length - target_idx[i+k-1])
        # return result
        target = max(nums)
        n = len(nums)
        count = 0
        result = 0
        left = 0
        for right in range(n):
            if nums[right] == target:
                count += 1
            while count >= k:
                result += n - right
                if nums[left] == target:
                    count -= 1 
                left += 1
        return result

if __name__ == "__main__":
    nums = [61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82]
    k = 2
    # nums = [1,3,2,3,3]
    # k = 2
    print(Solution().countSubarrays(nums=nums,k=k))