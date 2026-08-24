class Solution:
    def sumGame(self, num: str) -> bool:
        left_sum, right_sum, left_qu, right_qu = 0, 0, 0, 0
        for i in range(len(num) // 2):
            if num[i] == "?":
                left_qu += 1
            else:
                left_sum += int(num[i])
        for i in range(len(num) // 2, len(num)):
            if num[i] == "?":
                right_qu += 1
            else:
                right_sum += int(num[i])
        if (left_qu + right_qu) % 2 == 1:
            return True
        elif left_sum - right_sum != 4.5 * (right_qu - left_qu):
            return True
        else:
            return False
