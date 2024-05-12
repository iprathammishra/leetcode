class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:

        n = len(grid)
        out = [[0]*(n-2) for _ in range(n-2)]

        for row in range(n-2):
            for m in range(n-2):
                mx = 0
                for r in range(3):
                    for c in range(3):
                        mx = max(mx, grid[row+r][m+c])
                out[row][m] = mx
        return out

# directions=[
#     (1,0), # Down
#     (-1,0), # Up
#     (0,1), # Right
#     (0,-1), # Left
#     (1, 1), # Right-Positive Diagonal
#     (-1,-1) # Right-Negative Diagonal
#     (0,0) # Same
#     (1,-1) # Left-Positive Diagonal
#     (-1,1) # Right-Negative Diagonal
# ]
