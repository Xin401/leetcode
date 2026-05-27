class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        mid_length = (m + n + 1) // 2
        if m > n:
            return self.findMedianSortedArrays(nums2, nums1)
        if m == 0:
            return (nums2[(n - 1) // 2] + nums2[n // 2]) / 2

        left = 0
        right = m
        while left <= right:
            nums1_cut = left + (right - left) // 2
            nums2_cut = mid_length - nums1_cut
            nums1_left_max = nums1[nums1_cut - 1] if nums1_cut > 0 else -(10e6 + 1)
            nums1_right_min = nums1[nums1_cut] if nums1_cut < m else (10e6 + 1)
            nums2_left_max = nums2[nums2_cut - 1] if nums2_cut > 0 else -(10e6 + 1)
            nums2_right_min = nums2[nums2_cut] if nums2_cut < n else (10e6 + 1)
            # print(nums1_cut, nums2_cut)
            # print(nums1_left_max, nums1_right_min)
            # print(nums2_left_max, nums2_right_min)
            if nums1_left_max <= nums2_right_min and nums2_left_max <= nums1_right_min:
                if (m + n) % 2 == 1:
                    return max(nums1_left_max, nums2_left_max)
                else:
                    return (
                        max(nums1_left_max, nums2_left_max)
                        + min(nums1_right_min, nums2_right_min)
                    ) / 2
            elif nums2_left_max > nums1_right_min:
                left = nums1_cut + 1
            else:
                right = nums1_cut - 1
        return -1


# if __name__ == "__main__":
#     print(Solution().findMedianSortedArrays(nums1=[1, 3], nums2=[2]))
