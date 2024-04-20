class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        def dfs(row,col):
            nonlocal dirs,tm
            land[row][col]=0
            for i in range(4):
                newrow,newcol=row+dirs[i],col+dirs[i+1]
                if newrow>=0 and newrow<len(land) and newcol>=0 and newcol<len(land[0]) and land[newrow][newcol]==1:
                    dfs(newrow,newcol)
                    tm.append([newrow,newcol])
        posi,tm=[],[]
        dirs=[-1,0,1,0,-1]
        for row in range(len(land)):
            for col in range(len(land[0])):
                tm=[]
                if land[row][col]==1:
                    tm.append([row,col])
                    dfs(row,col)
                    posi.append(tm)
        posi=[sorted(p) for p in posi]
        return [[p[0][0],p[0][1],p[-1][0],p[-1][1]] for p in posi]