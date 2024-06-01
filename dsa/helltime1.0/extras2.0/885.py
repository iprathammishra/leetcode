class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:

        def inbounds(row, col):
            if 0 <= row < rows and 0 <= col < cols:
                return True
            return False

        cnt = 0
        row, col = rStart, cStart
        res = [[row, col]]

        one = 1
        two = 2

        while len(res) < rows*cols:

            for _ in range(one):
                col += 1
                if inbounds(row, col):
                    res.append([row, col])

            for _ in range(one):
                row += 1
                if inbounds(row, col):
                    res.append([row, col])

            for _ in range(two):
                col -= 1
                if inbounds(row, col):
                    res.append([row, col])

            for _ in range(two):
                row -= 1
                if inbounds(row, col):
                    res.append([row, col])

            one += 2
            two += 2

        return res
