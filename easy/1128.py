from typing import List

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        myDict = {}
        result = 0
        for d in dominoes:
            if d[0] < d[1]:
                domino = str(d[0]) + str(d[1])
            else:
                domino = str(d[1]) +  str(d[0])
            if domino not in myDict:
                myDict[domino] = 1
            else:
                result += myDict[domino]
                myDict[domino] += 1
        return result
    
if __name__ == "__main__":
    dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
    print(Solution().numEquivDominoPairs(dominoes=dominoes))