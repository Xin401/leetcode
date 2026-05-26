from typing import List


class Solution:
    def searchLeftBond(self, nums: List[int], target: int) -> List[int]:
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] >= target:
                right = mid - 1
            else:
                left = mid + 1
        if left > len(nums) - 1 or nums[left] != target:
            return -1
        return left

    def searchRightBond(self, nums: List[int], target: int) -> List[int]:
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        if right < 0 or nums[right] != target:
            return -1
        return right

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1, -1]
        leftBond = self.searchLeftBond(nums, target)
        rightBond = self.searchRightBond(nums, target)
        return [leftBond, rightBond]
