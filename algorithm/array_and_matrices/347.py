from typing import List
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    #     myDict = {}
    #     for n in nums:
    #         if n not in myDict:
    #             myDict[n] = 1
    #         myDict[n] += 1
    #     ret = sorted([(n,count) for n, count in myDict.items()], key=lambda item: item[1],reverse=True)
    #     return [n for n, count in ret][0:k]
        counts = Counter(nums)
        bucket = [[] for _ in range(max(counts.values()))]
        for n, count in counts.items():
            bucket[count-1].append(n)
        result = []
        for tmp in reversed(bucket):
            result += tmp
            if len(result) == k:
                return result


if __name__ == "__main__":
    nums = [1,2,2,3,3,3]
    k = 2
    print(Solution().topKFrequent(nums=nums, k = k))