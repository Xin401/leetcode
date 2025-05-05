from typing import List

class Solution:
    def addParenthesis(self, n : int,stack: List[str], left_count: int, current: str):
        if left_count == 0 and n == 0:
            stack.append(current)
            return
        if left_count == 0 and n != 0:
            self.addParenthesis(n-1,stack=stack,left_count=left_count+1,current=current+"(")
        elif left_count != 0 and n == 0:
            self.addParenthesis(n,stack=stack,left_count=left_count-1,current=current+")")
        else:
            self.addParenthesis(n-1,stack=stack,left_count=left_count+1,current=current+"(")
            self.addParenthesis(n,stack=stack,left_count=left_count-1,current=current+")")

    def generateParenthesis(self, n: int) -> List[str]:
        myStack = []
        self.addParenthesis(n, myStack, 0, "")
        return myStack
    
if __name__ == "__main__":
    print(Solution().generateParenthesis(n=3))
