from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        myStack = []
        for t in tokens:
            if t == '+':
                t1 = myStack.pop()
                t2 = myStack.pop()
                myStack.append(t2 + t1)
            elif t == '-':
                t1 = myStack.pop()
                t2 = myStack.pop()
                myStack.append(t2 - t1)
            elif t == '*':
                t1 = myStack.pop()
                t2 = myStack.pop()
                myStack.append(t2 * t1)
            elif t == '/':
                t1 = myStack.pop()
                t2 = myStack.pop()
                myStack.append(int(t2 / t1))
            else:
                myStack.append(int(t))
        return myStack[-1]
                


if __name__ == "__main__":
    tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    print(Solution().evalRPN(tokens=tokens))