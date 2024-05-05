class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        rows = len(heights)
        cols = len(heights[0])
        q = [[0, 0, 0]]
        visited = set()
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        while q:
            diff, row, col = heapq.heappop(q)
            if (row, col) in visited:
                continue
            visited.add((row, col))
            if (row, col) == (rows-1, cols-1):
                return diff
            for dr, dc in directions:
                newrow, newcol = dr+row, dc+col
                if newrow < 0 or newcol < 0 or newrow >= rows or newcol >= cols or (newrow, newcol) in visited:
                    continue
                mxdiff = max(
                    diff, abs(heights[newrow][newcol]-heights[row][col]))
                heapq.heappush(q, [mxdiff, newrow, newcol])
