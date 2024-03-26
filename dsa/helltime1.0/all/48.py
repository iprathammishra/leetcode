class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        size = len(matrix)
        for row in range(size >> 1):
            for col in range(size):
                matrix[row][col], matrix[size - row -
                                         1][col] = matrix[size - row - 1][col], matrix[row][col]
        for row in range(size):
            for col in range(row):
                matrix[row][col], matrix[col][row] = matrix[col][row], matrix[row][col]
