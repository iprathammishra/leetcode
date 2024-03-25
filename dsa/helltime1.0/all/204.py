class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3:
            return 0
        primes = [True] * n
        count = 0
        for current in range(2, n):
            if primes[current]:
                count += 1
            for multiple in range(current*2, n, current):
                primes[multiple] = False
        return count
