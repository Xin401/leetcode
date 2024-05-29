class Solution:
    def addOne(self, s: str) -> str:
        s = list(s)
        for i in range(len(s)-1, -1, -1):
            if s[i] == '0':
                s[i] = '1'
                break
            else:
                s[i] = '0'
        if s[0] == '0':
            s.insert(0, '1')
        return ''.join(s)
    def numSteps(self, s: str) -> int:
        if s == '1':
            return 0
        ret = 0
        while s != '1':
            if s[-1]=='0':
                s = s[:-1]
                ret += 1
            else:
                s = self.addOne(s)
                ret += 1
        return ret
    
if __name__ == "__main__":
    s = Solution()
    print(s.numSteps("101")) # 6
                