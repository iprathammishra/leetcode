class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:

        def func(idx):
            nonlocal ans, visited, n
            if idx == len(ans):
                return True

            if ans[idx]:
                return func(idx+1)
            else:
                for num in range(n, 0, -1):
                    if visited[num]:
                        continue
                    visited[num] = True
                    ans[idx] = num
                    if num == 1:
                        if func(idx+1):
                            return True
                    elif idx+num < len(ans) and ans[idx+num] == 0:
                        ans[num+idx] = num
                        if func(idx+1):
                            return True
                        ans[idx+num] = 0
                    ans[idx] = 0
                    visited[num] = False
            return False

        ans = [0]*(2*n - 1)
        visited = [False]*(n+1)

        func(0)
        return ans
