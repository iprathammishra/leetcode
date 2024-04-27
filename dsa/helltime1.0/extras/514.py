class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        memo = {}

        def cnt(cx, nx):
            sx = abs(cx-nx)
            sax = len(ring)-sx
            return min(sx, sax)

        def dfs(rx, kx, mn):
            if kx == len(key):
                memo[(rx, kx)] = 0
                return 0
            if (rx, kx) in memo:
                return memo[(rx, kx)]
            for cx in range(len(ring)):
                if ring[cx] == key[kx]:
                    mn = min(mn, cnt(rx, cx)+1+dfs(cx, kx+1, inf))
            memo[(rx, kx)] = mn
            return mn
        return dfs(0, 0, inf)
