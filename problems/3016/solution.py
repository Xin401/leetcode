class Solution:
    def minimumPushes(self, word: str) -> int:
        chars = {}
        res = 0
        for c in word:
            chars[c] = chars.get(c, 0) + 1
        chars_nums = sorted([chars[c] for c in chars], reverse=True)
        for i in range(len(chars_nums)):
            res += chars_nums[i] * (1 + i//8)
        return res

if __name__ == '__main__':
    s = Solution()
    print(s.minimumPushes("aabbccddeeffgghhiiiiii"))   