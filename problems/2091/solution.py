class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        length = len(nums)
        maximum = -100001
        minimum = 100001
        max_index = -1
        min_index = -1
        for i in range(length):
            if nums[i] > maximum:
                maximum = nums[i]
                max_index = i
            if nums[i] < minimum:
                minimum = nums[i]
                min_index = i
        ptr1 = min(max_index, min_index)
        ptr2 = max(max_index, min_index)
        return min(length - ptr1, ptr2 + 1, ptr1 + 1 + length - ptr2)
