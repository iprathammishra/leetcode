class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:

        def func(idx):
            nonlocal cnt
            if idx == n:
                cnt += 1
                return

            num = nums[idx]
            if num - k not in visited and num + k not in visited:
                visited[num] += 1
                func(idx+1)
                visited[num] -= 1
                if visited[num] == 0:
                    del visited[num]
            func(idx+1)

        cnt = 0
        n = len(nums)
        from collections import defaultdict
        visited = defaultdict(int)
        func(0)

        return cnt - 1
