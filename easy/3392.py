from typing import List

class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        result = 0
        for i in range(len(nums)-2):
            if nums[i] + nums[i+2] == nums[i+1]/2:
                result += 1
        return result
    
if __name__ == "__main__":
    nums = [1,2,1,4,1]
    print(Solution().countSubarrays(nums=nums))