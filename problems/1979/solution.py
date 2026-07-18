from typing import List


class Solution:
    def findGCD(self, nums: List[int]) -> int:
        m, n = max(nums), min(nums)

        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        return gcd(m, n)
