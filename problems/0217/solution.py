from typing import List
import numpy as np

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dictionary = {}
        for i in nums:
            if i in dictionary:
                return True
            else:
                dictionary[i] = 1
        return False


if __name__ == "__main__":
    print(Solution().containsDuplicate([1,1,1,3,3,4,3,2,4,2]))