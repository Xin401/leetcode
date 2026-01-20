from typing import List

class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        window_size = sum(nums)
        concated_list = nums + nums
        tmp = sum(concated_list[:window_size])
        res = len(nums)
        for i in range(len(nums)):
            if i > 0:
                tmp += concated_list[i + window_size - 1] - concated_list[i - 1]
            res = min(res, window_size - tmp)
        return res
    
if __name__ == '__main__':
    print(Solution().minSwaps([1,0,1,0,1]))
    print(Solution().minSwaps([0,0,0,1,0]))
    print(Solution().minSwaps([1,0,1,0,1,0,0,1,1,0,1]))