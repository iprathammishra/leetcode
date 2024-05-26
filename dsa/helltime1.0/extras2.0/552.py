class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 10**9 + 7

        if n == 1:
            return 3

        res = {
            (0, 0): 1, (0, 1): 1, (0, 2): 0,
            (1, 0): 1, (1, 1): 0, (1, 2): 0
        }

        for _ in range(n-1):
            tmp = collections.defaultdict(int)

            # p
            tmp[(0, 0)] = ((res[(0, 0)] + res[(0, 1)]) %
                           MOD + res[(0, 2)]) % MOD
            tmp[(1, 0)] = ((res[(1, 0)] + res[(1, 1)]) %
                           MOD + res[(1, 2)]) % MOD
            # l
            tmp[(0, 1)] = res[(0, 0)]
            tmp[(1, 1)] = res[(1, 0)]
            tmp[(0, 2)] = res[(0, 1)]
            tmp[(1, 2)] = res[(1, 1)]
            # a
            tmp[(1, 0)] = (tmp[(1, 0)] + (((res[(0, 0)] + res[(0, 1)]) %
                                           MOD + res[(0, 2)]) % MOD) % MOD) % MOD

            res = tmp

        return sum(res.values()) % MOD
