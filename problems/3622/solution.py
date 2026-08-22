class Solution:
    def checkDivisibility(self, n: int) -> bool:
        n_string: str = str(n)
        sum, product = 0, 1
        for c in n_string:
            sum += int(c)
            product *= int(c)
        return n % (sum + product) == 0
