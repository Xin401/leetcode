from typing import List


class Solution:
    def __init__(self):
        self.dict = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

    def letterCombinations(self, digits: str) -> List[str]:
        res: List[str] = []
        path: str = ""

        def backtrack(start_index: int):
            nonlocal path
            if start_index == len(digits):
                res.append(path)
                return
            for c in self.dict[int(digits[start_index])]:
                path += c
                backtrack(start_index + 1)
                path = path[:-1]

        backtrack(0)
        return res


# if __name__ == "__main__":
#     Solution().letterCombinations("23")
