class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        def reveal(i: int, j: int):
            mine_count = 0
            for x in range(max(i - 1, 0), min(i + 2, rows)):
                for y in range(max(j - 1, 0), min(j + 2, columns)):
                    if board[x][y] == "M":
                        mine_count += 1

            if mine_count > 0:
                board[i][j] = str(mine_count)
            else:
                board[i][j] = "B"
                for x in range(max(i - 1, 0), min(i + 2, rows)):
                    for y in range(max(j - 1, 0), min(j + 2, columns)):
                        if board[x][y] == "E":
                            reveal(x, y)

        rows, columns = len(board), len(board[0])

        click_row, click_col = click

        if board[click_row][click_col] == "M":
            board[click_row][click_col] = "X"
        else:
            reveal(click_row, click_col)

        return board
