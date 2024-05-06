import numpy as np

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = np.array(list(map(int, version1.split('.'))))
        v2 = np.array(list(map(int, version2.split('.'))))
        for i in range(min(len(v1),len(v2))):
            if v1[i] > v2[i]:
                return 1
            elif v1[i] < v2[i]:
                return -1
        if len(v1) > len(v2):
            if sum(v1[len(v2):]) > 0:
                return 1
        elif len(v1) < len(v2):
            if sum(v2[len(v1):]) > 0:
                return -1
        return 0

if __name__ == '__main__':
    version1 = "1.0.1"
    version2 = "1"
    sol = Solution()
    print(sol.compareVersion(version1, version2))