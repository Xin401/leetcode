class Solution:
    def maxProduct(self, n: int) -> int:
        m1 = m2 = -1
        while n != 0:
            if n % 10 >= m1:
                m2 = m1
                m1 = n % 10
            elif n % 10 >= m2:
                m2 = n % 10
            n //= 10
        return m1 * m2
