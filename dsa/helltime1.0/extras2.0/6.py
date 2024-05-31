class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        x = (len(s)//numRows if len(s)//numRows else numRows) 
        xx = x + x*(numRows-1 if numRows>=2 else 1)
        mtx = [[""]*xx for _ in range(numRows)]
        
        row, col = 0, 0
        cnt = 0
        while cnt < len(s):
            while row < numRows and cnt < len(s):
                mtx[row][col]= s[cnt]
                cnt += 1
                row += 1
            row -= 1
            if not row:
                col += 1
            while row and cnt < len(s):
                row -= 1
                col += 1
                mtx[row][col] = s[cnt]
                cnt += 1
            row += (1 if row+1<numRows else 0)

        ans = ""
        for mt in mtx:
            x = [m for m in mt if m]
            ans += ("".join(x))

        return ans
