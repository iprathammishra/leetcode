class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        gx = [[float("inf") for _ in range(n)] for _ in range(n)]
        for u, v, w in edges:
            gx[u][v] = gx[v][u] = w
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    gx[i][j] = min(gx[i][j], gx[i][k]+gx[k][j])
        k = float("inf")
        for i in range(n):
            cnt = 0
            for j in range(n):
                if i != j and gx[i][j] <= distanceThreshold:
                    cnt += 1
            if k >= cnt:
                k = cnt
                ans = i
        return ans
