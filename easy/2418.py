from typing import List
from operator import itemgetter

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [n for _, n in sorted(zip(heights,names),reverse = True)]

if __name__ == "__main__":
    names = ["Alex", "Ben", "Charlie", "David"]
    heights = [5, 3, 2, 6]
    s = Solution()
    print(s.sortPeople(names, heights))  # Charlie 2, Ben 3, Alex 5, David 6