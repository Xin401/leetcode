from typing import List

class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        count = 0
        for i in arr:
            if i % 2 != 0:
                count += 1
                if count == 3:
                    return True
            else:
                count = 0
        return False

if __name__ == '__main__':
    test = Solution()
    arr = [2,6,4,1]
    print(test.threeConsecutiveOdds(arr)) # False
