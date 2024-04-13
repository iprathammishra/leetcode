class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0])
        memo = {}

        def helper(r, c):
            if r >= rows or c >= cols:
                return 0
            if (r, c) not in memo:
                right = helper(r, c+1)
                down = helper(r+1, c)
                diagonal = helper(r+1, c+1)
                memo[(r, c)] = 0
                if matrix[r][c] == '1':
                    memo[(r, c)] = 1+min(right, down, diagonal)
            return memo[(r, c)]
        helper(0, 0)
        return max(memo.values())**2
