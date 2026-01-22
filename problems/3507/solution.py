from typing import List

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        
        result = 0
        while not all(nums[i] <= nums[i+1] for i in range(len(nums) - 1)):
            sum_array = [ nums[j] + nums[j + 1] for j in range(len(nums) - 1)]
            min_idx = sum_array.index(min(sum_array))
            nums[min_idx] += nums[min_idx + 1]
            del nums[min_idx + 1]
            result += 1
        return result
            

if __name__ == "__main__":
    sol = Solution()
    nums = [2,2,-1,3,-2,2,1,1,1,0,-1]
    print(sol.minimumPairRemoval(nums))