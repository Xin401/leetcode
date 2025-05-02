class Solution:
    def isValid(self, s: str) -> bool:
        check = []
        for paren in s:
            if paren == ')':
                if check and check[-1] == '(':
                    check.pop()
                else:
                    return False
            elif check and paren == '}':
                if check[-1] == '{':
                    check.pop()
                else:
                    return False
            elif check and paren == ']':
                if check[-1] == '[':
                    check.pop()
                else:
                    return False
            else:
                check.append(paren)
        return len(check) == 0
    
if __name__ == "__main__":
    s = "]"
    print(Solution().isValid(s = s))