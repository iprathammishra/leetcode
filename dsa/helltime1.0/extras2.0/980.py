class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        def dfs(i, j, visited, walk):
            if (i, j) == end:
                if walk == empty+1:
                    self.out += 1
                return
            if 0 <= i < rows and 0 <= j < cols and grid[i][j] != -1 and (i, j) not in visited:
                visited.add((i, j))
                for di, dj, in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                    ni, nj = i+di, j+dj
                    dfs(ni, nj, visited, walk+1)
                visited.remove((i, j))

        rows = len(grid)
        cols = len(grid[0])
        start = end = None
        empty = 0
        visited = set()
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1:
                    start = (row, col)
                elif grid[row][col] == 2:
                    end = (row, col)
                elif grid[row][col] == 0:
                    empty += 1
        self.out = 0
        dfs(start[0], start[1], visited, 0)
        return self.out
