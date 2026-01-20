from typing import List

class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        score_index = list(enumerate(score))
        score_index.sort(key=lambda x: x[1], reverse=True)
        for i in range(len(score_index)):
            if i == 0:
                score_index[i] = (score_index[i][0], "Gold Medal")
            elif i == 1:
                score_index[i] = (score_index[i][0], "Silver Medal")
            elif i == 2:
                score_index[i] = (score_index[i][0], "Bronze Medal")
            else:
                score_index[i] = (score_index[i][0], str(i + 1))
        score_index.sort(key=lambda x: x[0])
        return [value for index, value in score_index]

if __name__ == '__main__':
    sol = Solution()
    ret = sol.findRelativeRanks([5, 4, 6, 2, 1])
    for value in ret:
        print(value)