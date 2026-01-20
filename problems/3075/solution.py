from typing import List

class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness = sorted(happiness, reverse=True)
        ret = 0
        for i in range(k):
            if happiness[i]-i > 0:
                ret += happiness[i]-i
            else:
                break
        return ret
        

if __name__ == '__main__':
    happiness = [1, 2, 3, 4]
    k = 2
    print(Solution().maximumHappinessSum(happiness, k))