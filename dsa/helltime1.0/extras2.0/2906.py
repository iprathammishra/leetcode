class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        
        rows = len(grid)
        cols = len(grid[0])
        out = [[1]*cols for _ in range(rows)]

        product = 1
        i = 0
        for i in range(rows):
            for j in range(cols):
                out[i][j] = product % 12345
                product = (product*grid[i][j]) % 12345
        
        product = 1
        for i in range(rows-1, -1, -1):
            for j in range(cols-1, -1, -1):
                out[i][j] = (out[i][j]*product) % 12345
                product = (product * grid[i][j]) % 12345
        
        return out
