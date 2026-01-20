class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        n = len(s)
        cost = [abs(ord(s[i]) - ord(t[i])) for i in range(n)]
        left = 0
        right = 0
        sum_cost = 0
        max_len = 0
        while right < n:
            sum_cost += cost[right]
            while sum_cost > maxCost:
                sum_cost -= cost[left]
                left += 1
            max_len = max(max_len, right - left + 1)
            right += 1
        return max_len
    
if __name__ == '__main__':
    s = "abcd"
    t = "acde"
    maxCost = 0
    solution = Solution()
    print(solution.equalSubstring(s, t, maxCost))