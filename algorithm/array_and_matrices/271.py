from typing import List

class Solution:
    def encode(self, strs: List[str]) -> str:
        result = ""
        for s in strs:
            if len(s) < 10:
                result += "00" + str(len(s)) + s
            elif len(s) < 100:
                result += "0" + str(len(s)) + s
            else:
                result += str(len(s)) + s
        return result
    def decode(self, s: str) -> List[str]:
        result = []
        ptr = 0
        while ptr < len(s):
            num = int(s[ptr:ptr+3])
            result.append(s[ptr+3:ptr+3+num])
            ptr += 3 + num
        return result

        
if __name__ == "__main__":
    s = ["neet","code","love","you"]
    print(Solution().decode(Solution().encode(s)))