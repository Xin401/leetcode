from typing import List

class Solution:
    def numTeams(self, rating: List[int]) -> int:
        res = 0
        for i in range(1,len(rating)-1):
            left_smaller = len([x for x in rating[:i] if x < rating[i]])
            left_bigger = len([x for x in rating[:i] if x > rating[i]])
            right_smaller = len([x for x in rating[i+1:] if x < rating[i]])
            right_bigger = len([x for x in rating[i+1:] if x > rating[i]])
            res += left_smaller * right_bigger + left_bigger * right_smaller
            print(left_smaller, left_bigger, right_smaller, right_bigger)
        print(res)
        return res

if __name__ == "__main__":
    rating = [2,5,3,4,1]
    s = Solution()
    s.numTeams(rating)