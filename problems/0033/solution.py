from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        min_val = nums[0]
        min_pos = 0
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] < min_val:
                min_val = nums[mid]
                min_pos = mid
            if nums[mid] < nums[right]:
                right = mid - 1
            else:
                left = mid + 1
        if nums[min_pos] <= target and target <= nums[-1]:
            left = min_pos
            right = len(nums) - 1
        else:
            left = 0
            right = min_pos - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1
