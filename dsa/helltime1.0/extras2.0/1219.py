class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        def dfs(r, c):
            if r>=rows or c>=cols or grid[r][c]==0:
                return 0 
            res = 0

            original_val = grid[r][c]
            grid[r][c] = 0

            for dx, dy in directions:
                nr, nc = r + dx, c + dy
                if 0<=nr<rows and 0<=nc<cols:
                    res = max(res, dfs(nr, nc))
            
            grid[r][c] = original_val
            return res + original_val


        rows=len(grid)
        cols=len(grid[0])

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        mx=0
        for row in range(rows):
            for col in range(cols):
                if grid[row][col]:
                    mx = max(mx, dfs(row, col))
        return mx

