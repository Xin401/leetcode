from typing import List

class Solution:
    def count(self, length: int) -> int:
        return (1 + length) * length // 2
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ptr1 = 0
        ptr2 = 0
        last_ptr2 = -1
        result = 0
        current_sum = nums[0]
        while ptr2 <= len(nums):
            if ptr2 == len(nums):
                result += self.count(ptr2 - ptr1) 
                if last_ptr2 >= ptr1:
                    result -= self.count(last_ptr2 - ptr1 + 1)
                break
            if current_sum * (ptr2 - ptr1 + 1) >= k:
                result += self.count(ptr2 - ptr1) 
                if last_ptr2 >= ptr1:
                    result -= self.count(last_ptr2 - ptr1 + 1)
                last_ptr2 = ptr2 - 1
                if ptr1 == ptr2:
                    ptr2 += 1
                    if ptr2 < len(nums):
                        current_sum += nums[ptr2]
                current_sum -= nums[ptr1]
                ptr1 += 1
            else:
                ptr2 += 1
                if ptr2 < len(nums):
                    current_sum += nums[ptr2]
        return result


if __name__ == "__main__":
    nums = [2,1,4,3,5]
    k = 10
    print(Solution().countSubarrays(nums=nums,k=k))