class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        def pro(mat):
            sm=0
            for m in mat:
                sm+=(int("".join(map(str,m)), 2))
            return sm

        def flipRow(row):
            for i in range(len(row)):
                if row[i]==1:
                    row[i]=0
                else:
                    row[i]=1
            return row

        def reverseMat(mat):
            rows=len(mat)
            cols=len(mat[0])

            out=[[0]*rows for _ in range(cols)]

            for row in range(rows):
                for col in range(cols):
                    out[col][row]=grid[row][col]

            return out

        rows=len(grid)
        cols=len(grid[0])

        for idx, row in enumerate(grid):
            if row[0]==0:
                grid[idx] = flipRow(row)

        grid = reverseMat(grid)

        for idx, row in enumerate(grid):
            x="".join(map(str,row))
            if x.count('0')>x.count('1'):
                grid[idx] = flipRow(row)

        grid = reverseMat(grid)
        
        return pro(grid)