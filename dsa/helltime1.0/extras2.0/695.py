class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        def dfs(row, col):
            self.visited.append([row, col])
            for rd, cd in directions:
                nr, nc = row+rd, col+cd
                if 0 <= nr < rows and 0 <= nc < cols and [nr, nc] not in self.visited and grid[nr][nc]:
                    self.mx += 1
                    dfs(nr, nc)

        rows = len(grid)
        cols = len(grid[0])

        res = 0
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        self.visited = []
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] and [row, col] not in self.visited:
                    self.mx = 1
                    dfs(row, col)
                    res = max(res, self.mx)

        return res
