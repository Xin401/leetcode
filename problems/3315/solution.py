from typing import List

class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        result = [-1] * len(nums)

        for i in range(len(nums)):
            if nums[i] % 2 == 0:
                continue
            binary = list(format(nums[i], 'b'))
            for j in range(len(binary)-1, -1, -1):
                if binary[j] == '0':
                    binary[j+1] = '0'
                    result[i] = int(''.join(binary), 2)
                    break
                if j == 0:
                    binary[j] = '0'
                    result[i] = int(''.join(binary), 2)
        return result
        
if __name__ == "__main__":
    sol = Solution()
    print(sol.minBitwiseArray([2, 3, 5, 7]))  # [-1, 1, 4, 3]