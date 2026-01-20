from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        myStack = []
        result = [0 for _ in range(n)]
        for idx, t in enumerate(temperatures):
            while len(myStack) != 0 and t > myStack[-1][0]:
                result[myStack[-1][1]] = idx - myStack[-1][1]
                myStack.pop()
            myStack.append((t,idx))
        return result
    
if __name__ == "__main__":
    temperatures = [30,60,90]
    print(Solution().dailyTemperatures(temperatures=temperatures))