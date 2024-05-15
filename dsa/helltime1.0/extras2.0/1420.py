class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:

        MOD = 10**9 + 7

        @cache
        def func(idx, cost, mx):

            if idx == n:
                if cost == k:
                    return 1
                return 0

            res = 0
            for i in range(1, m+1):
                if (i > mx):
                    res += func(1+idx, 1+cost, i)
                else:
                    res += func(1+idx, cost, mx)

            return res % MOD

        return func(0, 0, -1) % MOD
