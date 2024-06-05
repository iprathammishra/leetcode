class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        mx = []
        for mat in matrix:
            mx.extend(mat)

        start = 0
        end = len(mx)
        while start < end:
            mid = (start + end) // 2

            if mx[mid] == target:
                return True

            if mx[mid] > target:
                end = mid
            else:
                start = mid + 1

        return False
