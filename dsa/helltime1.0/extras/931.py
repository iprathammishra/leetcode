class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        dp = [[float(inf) for _ in range(len(matrix[0]))]
              for _ in range(len(matrix))]
        ans = float(inf)

        def dfs(i, j):
            nonlocal dp
            if i == len(matrix):
                return 0
            if j < 0 or j >= len(matrix[0]):
                return float(inf)
            if dp[i][j] != float(inf):
                return dp[i][j]
            dp[i][j] = matrix[i][j] + \
                min(dfs(i+1, j-1), dfs(i+1, j), dfs(i+1, j+1))
            return dp[i][j]
        for i in range(len(matrix[0])):
            ans = min(ans, dfs(0, i))
        return ans
