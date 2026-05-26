from typing import List
from math import ceil


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        right = max(piles)
        left = 1
        while left <= right:
            mid = (left + right) // 2
            hours = sum(ceil(p / mid) for p in piles)
            if hours > h:
                left = mid + 1
            else:
                right = mid - 1
        return left
