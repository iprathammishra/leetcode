class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        def isValid(row, col, v):
            nrow = 3 * (row//3)
            ncol = 3 * (col//3)
            for i in range(9):
                if board[row][i] == v:
                    return False
                if board[i][col] == v:
                    return False
                if board[nrow + (i//3)][ncol + i % 3] == v:
                    return False

            return True

        def solve():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for k in range(1, 10):
                            if isValid(i, j, str(k)):
                                board[i][j] = str(k)

                                if solve():
                                    return True
                                else:
                                    board[i][j] = '.'
                        return False
            return True

        solve()
