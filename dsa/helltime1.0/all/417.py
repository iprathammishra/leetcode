class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        def bfs(queue, visited):
            while queue:
                for _ in range(len(queue)):
                    row, col = queue.popleft()
                    for delta_row, delta_col in [(0, -1), (0, 1), (1, 0), (-1, 0)]:
                        new_row, new_col = row + delta_row, col + delta_col
                        if (0 <= new_row < num_rows
                            and 0 <= new_col < num_columns
                            and (new_row, new_col) not in visited
                                and heights[new_row][new_col] >= heights[row][col]):

                            visited.add((new_row, new_col))
                            queue.append((new_row, new_col))

        num_rows, num_columns = len(heights), len(heights[0])

        visited_pacific, visited_atlantic = set(), set()

        pacific_queue = deque()
        atlantic_queue = deque()

        for row in range(num_rows):
            for col in range(num_columns):
                if row == 0 or col == 0:
                    visited_pacific.add((row, col))
                    pacific_queue.append((row, col))
                if row == num_rows - 1 or col == num_columns - 1:
                    visited_atlantic.add((row, col))
                    atlantic_queue.append((row, col))

        bfs(pacific_queue, visited_pacific)
        bfs(atlantic_queue, visited_atlantic)

        return [(row, col) for row in range(num_rows) for col in range(num_columns)
                if (row, col) in visited_pacific and (row, col) in visited_atlantic]
