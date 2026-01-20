class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        # n = len(dominoes)
        # left_force = [0 for _ in range(n)]
        # right_force = [0 for _ in range(n)]
        # force = 0
        # result = ''
        # for idx, f in enumerate(dominoes):
        #     if f == '.':
        #         force -= 1 if force > 0 else 0
        #     elif f == 'R':
        #         force = n
        #     else:
        #         force = 0
        #     right_force[idx] = force
        # force = 0
        # for idx, f in enumerate(reversed(dominoes)):
        #     if f == '.':
        #         force -= 1 if force > 0 else 0
        #     elif f == 'L':
        #         force = n
        #     else:
        #         force = 0
        #     left_force[idx] = force
        # left_force = list(reversed(left_force))
        # for idx in range(n):
        #     if right_force[idx] > left_force[idx]:
        #         result += "R"
        #     elif right_force[idx] < left_force[idx]:
        #         result += "L"
        #     else:
        #         result += "."
        # return result
        n = len(dominoes)
        right_force = [0 for _ in range(n)]
        left_force = [0 for _ in range(n)]
        right = 0
        left = 0
        result = ['' for _ in range(n)]
        for i in range(n):
            if dominoes[i] == '.':
                right -= 1 if right > 0 else 0
            elif dominoes[i] == 'R':
                right = n
            else:
                right = 0
            if dominoes[n-i-1] == '.':
                left -= 1 if left > 0 else 0
            elif dominoes[n-i-1] == 'L':
                left = n
            else:
                left = 0
            right_force[i] = right
            left_force[n-i-1] = left
        for i in range(n):
            if right_force[i] == left_force[i]:
                result[i] = '.'
            elif right_force[i] > left_force[i]:
                result[i] = 'R'
            else:
                result[i] = 'L'
        
        return "".join(result)

if __name__ == "__main__":
    dominoes = ".L.R...LR..L.."
    print(Solution().pushDominoes(dominoes=dominoes ))

