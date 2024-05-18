class Solution:
    def numberOfSets(self, n: int, maxDistance: int, roads: List[List[int]]) -> int:
        def floyd(mask, d):
            res = 0
            distance = [row[:] for row in d]

            for k in range(n):
                if mask & (1 << k):
                    for i in range(n):
                        if mask & (1 << i):
                            for j in range(n):
                                if mask & (1 << j):
                                    distance[i][j] = min(
                                        distance[i][j], distance[i][k] + distance[k][j])

            for i in range(n):
                if mask & (1 << i):
                    for j in range(n):
                        if mask & (1 << j):
                            res = max(res, distance[i][j])

            return res

        d = [[float('inf')] * n for _ in range(n)]
        for i in range(n):
            d[i][i] = 0

        for u, v, w in roads:
            d[u][v] = min(d[u][v], w)
            d[v][u] = min(d[v][u], w)

        comb = 1 << n
        res = 1
        for mask in range(1, comb):
            if floyd(mask, d) <= maxDistance:
                res += 1

        return res
