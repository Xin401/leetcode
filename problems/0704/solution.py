from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        m = len(nums)
        if nums[0] == target: return 0
        left = 0
        right = m - 1
        while left != right:
            if nums[left] == target:
                return left
            elif nums[right] == target:
                return right
            
            mid = (left + right) // 2
            print(left, right, mid, sep=',')
            if nums[mid] > target: 
                right-=1
            elif nums[mid] == target:
                return mid
            else:
                left+=1

        if nums[left] == target:
            return left
        return -1
    
if __name__ == '__main__':
    print(Solution().search([-1,0,3,5,9,12], 2))