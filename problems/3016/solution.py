class Solution:
    def minimumPushes(self, word: str) -> int:
        char = {}
        ret = 0
        for c in word:
            char[c] = char.get(c, 0) + 1
        freq = sorted([char[c] for c in char], reverse=True)
        for i in range(len(freq)):
            ret += freq[i] * (i // 8 + 1)
        return ret


# if __name__ == "__main__":
#     sol = Solution()
#     sol.minimumPushes("hii")
